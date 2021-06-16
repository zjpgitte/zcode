import java.util.ArrayList;

public class NewAccount extends Account
{
	private String _name;
	private ArrayList transactions;

	NewAccount(String name, int id, double balance)
	{
		_name = name;
		SetId(id);
		SetBalance(balance);
	}

	public String GetName()
	{
		return _name;
	}

	public void WithDraw(double money)
	{
		SetBalance(GetBalance() - money);

		transactions.add(new Transactions('W', money, GetBalance(), ""));
	}

	public void DePosit(double money)
	{
		SetBalance(GetBalance() + money);

		transactions.add(new Transactions('D', money, GetBalance(), ""));
	}

}