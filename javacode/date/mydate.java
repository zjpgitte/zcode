import java.util.GregorianCalendar;
import java.util.Calendar;
import java.util.Date;

public class mydate
{
	private int _year;
	private int _month;
	private int _day;

	mydate()
	{
		_year = 2000;
		_month = 1;
		_month = 1;
	}

	mydate(long elapsedtime)
	{
		Calendar d = new GregorianCalendar();
		d.setTimeInMillis(elapsedtime);
		_year = d.get(Calendar.YEAR);
		_month = d.get(Calendar.MONTH) + 1;
		_day = d.get(Calendar.DAY_OF_MONTH);
	}

	mydate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}



	public int getyear()
	{
		return _year;
	}

	public int getmonth()
	{
		return _month;
	}

	public int getday()
	{
		return _day;
	}
	public void setdate(long elapsedtime)
	{
		Calendar d = new GregorianCalendar();
		d.setTimeInMillis(elapsedtime);
		_year = d.get(Calendar.YEAR);
		_month = d.get(Calendar.MONTH) + 1;
		_day = d.get(Calendar.DAY_OF_MONTH);
	}


}