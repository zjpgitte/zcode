import java.util.Date

public class Account
{
	private int _id = 0;
	private double _balance = 0;
	private double _annualInterestRate = 0;
	private Date _dateCreat;

	Account()
	{
		_dateCreat = new Date();
	}


	Account(int id, double balance, double annualInterestRate)
	{
		_id = id;
		_balance = balance;
		_annualInterestRate = annualInterestRate;
	}

	public int GetId()
	{
		return _id;
	}

	public double GetBalance()
	{
		return _balance;
	}

	public double GetAnnualInterestRate()
	{
		return _annualInterestRate;
	}

	public Date GetDate()
	{
		return _dateCreat;
	}

	public void SetId(int id)
	{
		_id = id;
	}

	public void SetBalance(double balance)
	{
		_balance = balance;
	}

	public void SetAnnualInterestRate(double annualInterestRate)
	{
		_annualInterestRate = annualInterestRate;
	}

	public double GetMonthlyInterestRate()
	{

	}
}