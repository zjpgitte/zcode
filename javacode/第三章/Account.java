import java.util.Date;

public class Account {
    private int id = 0;
    private double balance = 0;
    private double annualInterestRate = 0;
    private Date dateCreated;

    public static void main(String[] args) {
        Account account = new Account(1122, 20000);
        account.setAnnualInterestRate(0.045);
        account.withDraw(2500);
        account.deposit(3000);
        System.out.println("Balance:"+account.getBalance()+"\n"+"MonthlyInterestRate:"+account.getMonthlyInterstRate()+"\n"+"DateCreated:"+account.getDateCreated());
    }

    public Account(){
        dateCreated = new Date();
    }
    public Account(int id, double balance){
        this.id = id;
        this.balance = balance;
        dateCreated = new Date();
    }

    public int getId() {
        return id;
    }
    public void setId(){
        this.id = id;
    }

    public double getBalance(){
        return balance;
    }
    public void setBalance(double balance){
        this.balance = balance;
    }

    public double getAnnualInterestRate(){
        return annualInterestRate;
    }
    public void setAnnualInterestRate(double annualInterestRate){
        this.annualInterestRate = annualInterestRate;
    }

    public Date getDateCreated(){
        return dateCreated;
    }

    public double getMonthlyInterstRate(){
        double monthlyinterstrate = annualInterestRate / 12;  
        return balance * monthlyinterstrate / 100;
    }

    public void withDraw(double money){  //取款
        balance -= money;
    }
    public void deposit(double money){   //存款
        balance += money;
    }
}