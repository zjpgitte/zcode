import java.util.ArrayList;
import java.util.Scanner;

public class test {

    public static void main(String[] args)
    {
        ArrayList<Inetger> list = new ArrayList<>();

        Scanner input = new Scanner(System.in);
        System.out.print("Enter intergers(input with 0): ");
        int value;

        while(value != 0)
        {
            value = input.nextInt();
            if(!list.contains(value) && value != 0)
            {
                list.add(value);
            }
        }

        for(int i = 0; i < list.size(); i++)
        {
            System.out.print(list.get(i) + " ");
        }
    }

}

