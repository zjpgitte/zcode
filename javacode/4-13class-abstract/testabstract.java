import java.util.ArrayList;

public class testabstract
{
	public static void main(String[] args)
	{
		ArrayList<Geometric> geo = new ArrayList<>();
		geo.add(new CircleFromGeo(2));
		geo.add(new CircleFromGeo(3));
		geo.add(new CircleFromGeo(4));
		geo.add(new CircleFromGeo(5));
		geo.add(new CircleFromGeo(6));
		geo.add(new RectangleFromGeo(3, 4));
		geo.add(new RectangleFromGeo(3, 0));
		geo.add(new RectangleFromGeo(100, 3));

		double maxArea = geo.get(0).GetAreas();
		int index = 0;
		for(int i = 0; i < geo.size(); i++)
		{
			if(geo.get(i).GetAreas() > maxArea)
			{
				maxArea = geo.get(i).GetAreas();
				index = i;
			}
		}

		System.out.println("the max area is " + maxArea + " index is " + index);
	}
}