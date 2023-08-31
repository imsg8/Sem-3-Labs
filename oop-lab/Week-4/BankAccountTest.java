class BankAccount {
    String depositorName;
    long accountNumber;
    String accountType;
    double balance;
    static double interestRate = 5.5;

    // Default Constructor
    BankAccount() {
        depositorName = "Shivang";
        accountNumber = 2322432;
        accountType = "Savings";
        balance = 0.0;
    }

    // Parameterized Constructor
    BankAccount(String name, long accNumber, String accType, double initialBalance) {
        depositorName = name;
        accountNumber = accNumber;
        accountType = accType;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        System.out.println("Deposited: " + amount);
    }

    void withdraw(double amount) {
        if (balance - amount >= 1000) {
            balance -= amount;
            System.out.println("Withdrawn: " + amount);
        } else {
            System.out.println("Insufficient balance.");
        }
    }

    void display() {
        System.out.println("Account Holder: " + depositorName);
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Account Type: " + accountType);
        System.out.println("Balance: " + balance);
        System.out.println("\n \n");
    }

    static void displayInterestRate() {
        System.out.println("Interest Rate: " + interestRate);
    }
}

class BankAccountTest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Using default constructor
        BankAccount account1 = new BankAccount();
        account1.display();

        // Using parameterized constructor
        BankAccount account2 = new BankAccount("Kartikeya", 123456789, "Savings", 5000.0);
        account2.display();

        // Deposit and withdraw
        System.out.print("\nEnter amount to deposit in account2: ");
        double depositAmount = scanner.nextDouble();
        account2.deposit(depositAmount);

        System.out.print("Enter amount to withdraw from account2: ");
        double withdrawAmount = scanner.nextDouble();
        account2.withdraw(withdrawAmount);

        // Display account details and interest rate
        System.out.println("\nAccount2 Details:");
        account2.display();

        System.out.println("\nInterest Rate:");
        BankAccount.displayInterestRate();
    }
}