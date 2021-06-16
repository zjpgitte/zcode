public class testGeo
{
	public static void main(String[] args)
	{
		Geometric geo1 = new CircleFromGeo(3);
		Geometric geo2 = new RectangleFromGeo(3, 5);

		System.out.println("the two geos have the same areas? " + IsSameAreas(geo1, geo2));

		DisplayGeo(geo1);

		System.out.println();

		DisplayGeo(geo2);

		
	}
	public static boolean IsSameAreas(Geometric geo1, Geometric geo2)
	{
			return geo1.GetAreas() == geo2.GetAreas();
	}

	public static void DisplayGeo(Geometric geo)
	{
		System.out.println("The areas is " + geo.GetAreas());
		System.out.println("The perimeter is " + geo.GetPerimeter());
	}	
}