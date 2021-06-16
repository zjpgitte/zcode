public class test
{
	public static void main(String[] args)
	{
		CircleFromGeo circle = new CircleFromGeo(2);
		System.out.println("Circle:");
		System.out.println("Radius: " + circle.GetRadius() + "  Areas: " + circle.GetAreas());
		System.out.println(circle.ToString());

		RectangleFromGeo rectangle = new RectangleFromGeo(2, 2, "red", true);
		System.out.println("rectangle:");
		System.out.println("width: " + rectangle.GetWidth() + " height:" + rectangle.GetHeight() + " Areas:" + rectangle.GetAreas() + " Perimeter:" + rectangle.GetPerimeter());
		System.out.println(rectangle.ToString());

	}
}