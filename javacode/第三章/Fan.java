public class Fan {
    static int SLOW = 1;
    static int MEDIUM = 2;
    static int FAST =3;
    private int speed = SLOW;
    private boolean on = false;
    private double radius = 5;
    String  color = "Blue";

    public static void main (String[] args){
        Fan fan_1 = new Fan();
        Fan fan_2 = new Fan();

        fan_1.setOn(true);
        fan_1.setColor("Yellow");
        fan_1.setSpeed(Fan.FAST);
        fan_1.setRadius(10);
        System.out.println(fan_1.toString());

        fan_2.setOn(false);
        fan_2.setColor("Red");
        fan_1.setSpeed(Fan.MEDIUM);
        fan_1.setRadius(8);
        System.out.println(fan_2.toString());
    }

    public Fan(){
    }

    public int getSpeed() {
        return speed;
    }
    public void setSpeed(int speed) {
        this.speed = speed;
    }

    public boolean getOn() {
        return on;
    }
    public void setOn(boolean on) {
        this.on = on;
    }

    public double getRadius(){
        return radius;
    }
    public void setRadius(double radius) {
        if (on)
        this.radius = radius;
    }

    public String getColor(){
        return color;
    }
    public void setColor(String color){
        if (on)
        this.color = color;
    }

    public String toString(){
        if(on){
            return speed + " " + color + " " + radius;
        }else
            return "fan is off" + " "+ color + " " + radius;
    }
}