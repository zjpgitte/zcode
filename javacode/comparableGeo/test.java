import java.util.ArrayList;
import java.util.Collections;

public class test
{
	public static void main(String[] args)
	{
		ArrayList<ComparableGeo> list = new ArrayList<>();

		list.add(new CircleFromGeo(3));
		list.add(new CircleFromGeo(5));
		list.add(new RectangleFromGeo(3,4));
		list.add(new RectangleFromGeo(3,5));`	

		System.out.println("max: " + java.util.Collections.max(list));

		java.util.Collections.sort(list);

		for(int i = 0; i < list.size(); i++)
		{
			System.out.println(list.get(i));
		}

	}
}