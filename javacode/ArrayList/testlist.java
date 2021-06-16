import java.util.ArrayList;

class testlist
{
	public static void main(String args[])
	{
		ArrayList<String> cityList = new ArrayList<>();
		cityList.add("London");
		cityList.add("Denver");
		cityList.add("Paris");
		cityList.add("Miami");
		cityList.add("Seoul");
		cityList.add("Tokyo");
		System.out.println("List Size: " + cityList.size());
		System.out.println("Is Miami in list? " + cityList.contains("Miami"));
		System.out.println("The location of Denver in the list? " + cityList.indexOf("Denver"));
		System.out.println("List Is Empty? " + cityList.isEmpty());

		cityList.add(2, "xian");
		cityList.remove("Miami");
		cityList.remove(1);

		System.out.println(cityList.toString());

		for(int i = 0; i < cityList.size(); i++)
		{
			System.out.print(cityList.get(i) + " ");
		}
		System.out.println();

		ArrayList<CircleFromGeo> list  = new ArrayList<>();
		list.add(new CircleFromGeo(2));
		list.add(new CircleFromGeo(3));

		System.out.println("The area of the circle: " + list.get(0).GetAreas());

	}
}