import java.math.*;

public class test
{
	public static void main(String[] args)
	{
		System.out.println(fac(123));
	}

	public static BigInteger fac(long n)
	{
		BigInteger res = new BigInteger("1");
		for(int i = 1; i <= n; i++)
		{
			res = res.multiply(new BigInteger(i + ""));
		}
		return res;
	}
}