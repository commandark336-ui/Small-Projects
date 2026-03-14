int choice;
    double num1, num2;

    while (true) {
        cout << "\n===== Simple Calculator =====\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting calculator. Goodbye!\n";
            break;
        }

        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        switch (choice) {
            case 1:
                cout << "Result: " << calc.add(num1, num2) << endl;
                break;
            case 2:
                cout << "Result: " << calc.subtract(num1, num2) << endl;
                break;
            case 3:
                cout << "Result: " << calc.multiply(num1, num2) << endl;
                break;
            case 4:
                cout << "Result: " << calc.divide(num1, num2) << endl;
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
