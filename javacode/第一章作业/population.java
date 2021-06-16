public class population
{
	private int _population = 312032486;
	private int _secondsOfYear = 365 * 24 * 60 * 60;

	public population()
	{

	}

	public int GetYearPopulation(int year)
	{
		double seconds = year * _secondsOfYear;
		_population += seconds / 7 - seconds / 13 + seconds / 45 ;

		return _population;
	}
} 