public class Geometric
{
	private String _color = "white";
	private boolean _filled;
	private java.util.Date _dateCreat;

	public Geometric()
	{
		_dateCreat = new java.util.Date();
	}

	public Geometric(String color , boolean filled)
	{
		_color = color;
		_filled = filled;
	}

	public String GetColor()
	{
		return _color;
	}

	public void SetColor(String color)
	{
		_color = color;
	}

	public boolean IsFilled()
	{
		return _filled;
	}

	public void SetFilled(boolean filled)
	{
		_filled = filled;
	}

	public java.util.Date GetDateCreat()
	{
		return _dateCreat;
	}

	public String ToString()
	{
		return "creat on: " + _dateCreat + "\ncolor: " + _color + "\nis filled: " + _filled;
 	}

}