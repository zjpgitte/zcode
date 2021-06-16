class TV
{
	int chanel = 1;
	int volume = 1;
	boolean on = false;
	TV()
	{

	}
	public void SetChanel(int newChanel)
	{
		if(on && newChanel >=1 && newChanel <= 120)
		chanel = newChanel;
	}
	public void SetVolume(int newVolume)
	{
		if (on && newVolume >= 1 && newVolume <= 7) 
		volume = newVolume;
	}
	public void TurnOn()
	{
		on = true;
	}
	public void TurnOff()
	{
		on = false;
	}
	public void ChanelUp()
	{
		if(on && chanel < 120)
		{
			chanel++;
		}
	}
	public void ChanelDown()
	{
		if(!on && chanel > 1)
		{
			chanel--;
		}
	}
	public void VolumeUp()
	{
		if(on && volume < 7)
		{
			volume++;
		}
	}
	public void VolumeDown()
	{
		if(on && volume > 1)
		{
			volume--;
		}
	}

}