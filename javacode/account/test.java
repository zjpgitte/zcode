public class test
{
	public static void main(String[] args)
	{
		NewAccount a = new NewAccount("George", 1122, 1000);
		a.SetBalance(0.015);

		a.DePosit(30);
		a.DePosit(40);
		a.DePosit(50);

		a.WithDraw(5);
		a.WithDraw(4);
		a.WithDraw(2);

		System.out.println("name " + a.GetName() + " annualInterestRate " + a.GetAnnualInterestRate() + " balance " + a.GetBalance());
	}
}