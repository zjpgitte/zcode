public class ComparableGeo extends Geometric implements Comparable<ComparableGeo>
{
	public int compareTo(ComparableGeo o)
	{
		if(GetAreas() > o.GetAreas())
		{
			return 1;
		}
		else if(GetAreas() < o.GetAreas())
		{
			return -1;
		}
		else 
		{
			return 0;
		}
	}
}