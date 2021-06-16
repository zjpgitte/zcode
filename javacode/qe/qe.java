public class qe{
	double _a;
	double _b;
	double _c;

	qe()
	{
		_a = 1.0;
		_b = 1.0;
		_c = 1.0;
	}

	qe(double a, double b, double c){
		_a = a;
		_b = b;
		_c = c;
	}

	double GetA(){
		return _a;
	}

	double GetB(){
		return _b;
	}

	double GetC(){
		return _c;
	}

	double GetDiscriminant()
	{
		return _b * _b - 4 * _a * _c;
	}

	double GetRoot1()
	{

		double Dis = GetDiscriminant();
		if(Dis < 0)
		{
			System.out.println("no root");
		}
		return (-1 * _b + Math.sqrt(Dis)) / 2 * _a;
	}

	double GetRoot2()
	{

		double Dis = GetDiscriminant();
		if(Dis < 0)
		{
			System.out.println("no root");
		}
		return (-1 * _b - Math.sqrt(Dis)) / 2 * _a;
	}
}