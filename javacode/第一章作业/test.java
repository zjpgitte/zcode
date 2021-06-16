public class test
{
	public static void main(String[] args)
	{
		population p = new population();
		System.out.println("next one year population: " + p.GetYearPopulation(1));
		System.out.println("next two year population: " + p.GetYearPopulation(2));
		System.out.println("next three year population: " + p.GetYearPopulation(3));
		System.out.println("next four year population: " + p.GetYearPopulation(4));
		System.out.println("next five year population: " + p.GetYearPopulation(5));
	}
}