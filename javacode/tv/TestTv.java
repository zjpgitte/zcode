


public class TestTv{
	public static void main(String[] args)
	{
		TV t1 = new TV();
		t1.TurnOn();
		t1.SetChanel(30);
		t1.ChanelDown();
		t1.SetVolume(3);
		t1.VolumeDown();
		System.out.println("Chanel:" + t1.chanel + "   volume:" + t1.volume);

		TV t2 = new TV();
		t2.TurnOn();
		t2.ChanelUp();
		t2.VolumeUp();
		System.out.println("Chanel:" + t2.chanel + "   volume:" + t2.volume);

	}
}