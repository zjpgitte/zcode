public class RectangleFromGeo extends Geometric
{
	private double _width;
	private double _height;

	public RectangleFromGeo()
	{
		_width = 0;
		_height = 0;
	}

	public RectangleFromGeo(double width, double height)
	{
		_width = width;
		_height = height;
	}

	public RectangleFromGeo(double width, double height, String color, boolean filled)
	{
		_width = width;
		_height = height;
		SetColor(color);
		SetFilled(filled);
	}

	public void SetWidth(double width)
	{
		_width = width;
	}

	public double GetWidth()
	{
		return _width;
	}

	public void SetHeight(double height)
	{
		_height = height;
	}

	public double GetHeight()
	{
		return _height;
	}

	public double GetAreas()
	{
		return _width * _height;
	}

	public double GetPerimeter()
	{
		return 2 * (_width + _height);
	}
}