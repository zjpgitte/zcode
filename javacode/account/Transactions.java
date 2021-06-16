import java.util.Date;
public class Transactions
{
	Date _date; // 交易日期
	char _type; //交易类型
	double _amount; 
	double _balance; // 交易余额
	String _description; // 交易描述

	Transactions(char type, double amount, double balance,String description)
	{
		_type = type;
		_amount = amount;
		_balance = balance;
		_description = description;
	}


}