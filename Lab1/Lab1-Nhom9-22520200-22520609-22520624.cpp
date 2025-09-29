#include <stdio.h>

void PrintBits(unsigned int x)
{
	int i;
	for (i = 8 * sizeof(x) - 1; i >= 0; i--)
	{
		(x & (1 << i)) ? putchar('1') : putchar('0');
	}
	printf("\n");
}
void PrintBitsOfByte(unsigned int x)
{
	int i;
	for (i = 7; i >= 0; i--)
	{
		(x & (1 << i)) ? putchar('1') : putchar('0');
	}
	printf("\n");
}

// 1.1
int bitOr(int x, int y)
{
	// PrintBits(x);
	// PrintBits(y);
	return ~(~x & ~y);
}

// 1.2
int negative(int x)
{
	return ~x + 1; // dùng bù 2
}

// 1.3
int getHexcha(int x, int n)
{
	int shiftAmount = n << 2; // Tính số bit cần dịch: n * 4, tương đương n << 2
    // Dịch phải x để đưa byte thứ n về vị trí thấp nhất
    int result = x >> shiftAmount; 
    // Dùng mask 0xFF để xóa tất cả các bit trừ 8 bit cuối cùng
    return result & 0xF;  
}

// 1.4
int flipByte(int x, int n)
{
	int mask = 255 << (n << 3);
	return (x & ~mask) | ((x ^ mask) & mask);
}

// 1.5
int divpw2(int x, int n)
{
	return x << (~n + 1);
}

// 2.1
int isEqual(int x, int y)
{
	return !(x ^ y); // 2 số bằng nhau khi đảo ngược bit của số a and với số b bằng 0
}

// 2.2
int is16x(int x)
{
	return 0;
}

// 2.3
int isPositive(int x)
{
	// Điều kiện 1: x không phải là số âm (tức là x >= 0).
    // (x >> 31) sẽ là 0 nếu x không âm, và -1 nếu x âm.
    // !(x >> 31) sẽ là 1 nếu x không âm, và 0 nếu x âm.
	int NotNegative = !(x >> 31);

    // Điều kiện 2: x không bằng 0.
    //     !x → đảo ngược logic, trả về 1 nếu x = 0, ngược lại 0 nếu x ≠ 0.
    // Thêm một ! nữa → !!x trả về 1 nếu x ≠ 0, và 0 nếu x = 0.
    int NotZero = !!x;

    // x là số dương khi và chỉ khi nó "không âm" VÀ "không bằng 0".
    // Ta dùng & bitwise vì các toán hạng đều là 0 hoặc 1.
    return NotNegative & NotZero;
}

// 2.4
int isGE2n(int x, int y)
{
	return 0;
}

int main()
{
	int score = 0;
	printf("Your evaluation result:");
	printf("\n1.1 bitOr");
	if (bitOr(3, -9) == (3 | -9))
	{
		printf("\tPass.");
		score += 1;
	}
	else
		printf("\tFailed.");

	printf("\n1.2 negative");
	if (negative(0) == 0 && negative(9) == -9 && negative(-5) == 5)
	{
		printf("\tPass.");
		score += 1;
	}
	else
		printf("\tFailed.");

	// 1.3
	printf("\n1.3 getHexcha");
	if (getHexcha(26, 0) == 0xa && getHexcha(0x11223344, 1) == 0x4)
	{
		printf("\tPass.");
		score += 2;
	}
	else
		printf("\tFailed.");

	printf("\n1.4 flipByte");
	if (flipByte(10, 0) == 245 && flipByte(0, 1) == 65280 && flipByte(0x5501, 1) == 0xaa01)
	{
		printf("\tPass.");
		score += 3;
	}
	else
		printf("\tFailed.");
	// 1.5
	printf("\n1.5 divpw2");
	if (divpw2(10, -1) == 20 && divpw2(15, -2) == 60 && divpw2(2, -4) == 32)
	{
		if (divpw2(10, 1) == 5 && divpw2(50, 2) == 12)
		{
			printf("\tAdvanced Pass.");
			score += 4;
		}
		else
		{
			printf("\tPass.");
			score += 3;
		}
	}
	else
		printf("\tFailed.");

	printf("\n2.1 isEqual");
	if (isEqual(4, 2) == 0 && isEqual(-4, -4) == 1 && isEqual(0, 10) == 0)
	{
		printf("\tPass.");
		score += 2;
	}
	else
		printf("\tFailed.");

	// 2.2
	printf("\n2.2 is16x");
	if (is16x(16) == 1 && is16x(23) == 0 && is16x(0) == 1)
	{
		printf("\tPass.");
		score += 2;
	}
	else
		printf("\tFailed.");

	printf("\n2.3 isPositive");
	if (isPositive(10) == 1 && isPositive(-5) == 0 && isPositive(0) == 0)
	{
		printf("\tPass.");
		score += 3;
	}
	else
		printf("\tFailed.");

	// 2.4
	printf("\n2.4 isGE2n");
	if (isGE2n(12, 4) == 0 && isGE2n(8, 3) == 1 && isGE2n(15, 2) == 1)
	{
		printf("\tPass.");
		score += 3;
	}
	else
		printf("\tFailed.");

	printf("\n--- FINAL RESULT ---");
	printf("\nScore: %.1f", (float)score / 2);
	if (score < 5)
		printf("\nTrouble when solving these problems? Contact your instructor to get some hints :)");
	else
	{
		if (score < 8)
			printf("\nNice work. But try harder.");
		else
		{
			if (score >= 10)
				printf("\nExcellent. We found a master in bit-wise operations :D");
			else
				printf("\nYou're almost there. Think more carefully in failed problems.");
		}
	}

	printf("\n\n\n");
}