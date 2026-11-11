#include <iostream>
#include <string>

using namespace std;

void addrecord(string APP, string &APP_Ans, int &App_count, float &App_HpD, int watt, float &Twatt, int x)
{
    cout << "*\tDo you have a/an " << APP << "? (Yes/No): "; cin >> APP_Ans;
    if (APP_Ans == "Yes" || APP_Ans == "yes" || APP_Ans == "YES")
    {
        cout << "*\tHow many do you have in home: "; cin >> App_count;
        cout << "*\tHow many Total Hours/Day do you use " << APP << "?: "; cin >> App_HpD;
    }
    Twatt = watt * App_count;
}

void deleterecord(string APP, string &APP_Ans, int &App_count, float &App_HpD, float &Twatt, int x)
{
    string APPD_Ans;
    if (APP_Ans == "Yes" || APP_Ans == "yes" || APP_Ans == "YES")
    {
        cout << "*\t" << APP << "?: "; cin >> APPD_Ans;
        cout << endl;
        if (APPD_Ans == "Yes" || APPD_Ans == "yes" || APPD_Ans == "YES")
        {
            App_count = 0;
            App_HpD = 0;
            Twatt = 0;
        }
    }
}

void editrecord(string APP, string DE_Ans, int &App_count, float &App_HpD, float &Twatt, int &watt)
{
    string Edit_Ans;
    if (DE_Ans == "Yes" || DE_Ans == "yes" || DE_Ans == "YES")
    {
        cout << "\n*\tDo you want to edit " << APP << "? (Yes/No): "; cin >> Edit_Ans;
        if (Edit_Ans == "Yes" || Edit_Ans == "yes" || Edit_Ans == "YES")
        {
            cout << "*\t[EDIT]How many do you have in home: "; cin >> App_count;
            cout << "*\t[EDIT]How many Total Hours/Day do you use " << APP << "?: "; cin >> App_HpD;
        }
    }
    else
        if (App_count > 0)
        {
            cout << "\n*\tDo you want to edit " << APP << "? (Yes/No): "; cin >> Edit_Ans;
            if (Edit_Ans == "Yes" || Edit_Ans == "yes" || Edit_Ans == "YES")
            {
                        cout << "*\t[EDIT]How many do you have in home: "; cin >> App_count;
                        cout << "*\t[EDIT]How many Total Hours/Day do you use " << APP << "?: "; cin >> App_HpD;
            }
        }
    Twatt = watt * App_count;
}

void viewrecord (string name, string UserN, float KwPerHour, float KwHourPerMonth, float RatePerMonth)
{
    cout << "\n\t\t\t\t\t\t\t\t LMC ELECTRIC BILLING" << endl;
    cout << "*\t" << name << endl;
    cout << "*\t" << UserN << endl;
    cout << "________________________________________________________________________________________________________________________________________________________________________" << endl;
    cout << "\n*\t\t\t\t\t\t\t\t PREVIOUS READING" << endl;
    cout << "\n\n*\tTotal Kilowatts per Hour " << "\t\t\t\t\t\t" << "(Kw/H):" << "\t\t\t\t\t\t" << "8.5" << endl;
    cout << "*\tTotal Kilowatts/Hour per Month " << "\t\t\t\t\t\t" << "(KwH/M):" << "\t\t\t\t\t" << "255" << endl;
    cout << "________________________________________________________________________________________________________________________________________________________________________" << endl;
    cout << "*\tTotal Amount " << "\t\t\t\t\t\t\t\t" << "(KwH/Mo/Php):" << "\t\t\t\t\tP" << "3,037" << endl;
    cout << "________________________________________________________________________________________________________________________________________________________________________" << endl;
    cout << "\n*\t\t\t\t\t\t\t\t CURRENT READING" << endl;
    cout << "\n\n*\tTotal Kilowatts per Hour " << "\t\t\t\t\t\t" << "(Kw/H):" << "\t\t\t\t\t\t" << KwPerHour << endl;
    cout << "*\tTotal Kilowatts/Hour per Month " << "\t\t\t\t\t\t" << "(KwH/M):" << "\t\t\t\t\t" << KwHourPerMonth << endl;
    cout << "________________________________________________________________________________________________________________________________________________________________________" << endl;
    cout << "*\tTotal Amount " << "\t\t\t\t\t\t\t\t" << "(KwH/Mo/Php):" << "\t\t\t\t\tP" << RatePerMonth << endl;
    cout << "========================================================================================================================================================================" << endl;
}

void searchrecord (string App, int watt, float App_HpD, float KwHM)
{
    cout << "========================================================================================================================================================================" << endl;
    cout << "*\t" << App << "\t\t\t\t" << "Wattage: " << watt << "\t\t\t\t" << "Hours/DAY: " << App_HpD << "\t\t\t\t" << "KWH/MO: " << KwHM << endl;
    cout << "========================================================================================================================================================================" << endl;
}


int main()
{
    string Acc_ans, UserN, Pass, name, C_pass, D_Ans, DE_Ans, E_Ans, S_Ans, P_Ans, R_Ans;
    string AppD_Ans[10];
    string App[10] = {"Air Conditioning Unit", "Clothes Dryer", "Computer (with monitor)", "Cooker, Rice", "Fan", "Flat Iron", "Incandescent Bulb", "Refrigerator", "Television", "Washing Machine"};
    string App_Ans[10];
    int App_count[10] = {0}, x, I_Ans, y, watt[10] = {2664, 250, 225, 1000, 90, 600, 10, 185, 90, 280}, RatePerMonthNoCent = 0;
    float App_HpD[10] = {0}, App_Twatt[10] = {0};
    float KwH[10] = {0}, KwHM[10] = {0}, KwHourPerMonth = 0, KwPerHour = 0, RatePerMonth = 0, Payment = 0, Change = 0, Balance = 0;

    cout << "\n\n\t\t\t\t\t\t\t\t WELCOME TO THE LMC ELECTRIC BILLING SYSTEM" << endl;
    cout << endl;
    cout << "========================================================================================================================================================================" << endl;
    cout << "*\tDo you already have an Account? (Yes/No): ";
    cin >> Acc_ans;
    cout << endl;
    if (Acc_ans == "Yes" || Acc_ans == "yes" || Acc_ans == "YES")
    {
        cout << "\n*\t\t\t\t\t\t USERNAME (NoSpace/NoSpecialCharac): "; cin >> UserN;
        cout << "*\t\t\t\t\t\t PASSWORD (NoSpace/NoSpecialCharac): "; cin >> Pass;
        cout << "\n*\t\t\t\t\t\t ENTER YOUR REGISTERED NAME (LAST NAME, FIRST NAME MI.): ";
        getline(cin >> ws, name);
        cout << "________________________________________________________________________________________________________________________________________________________________________" << endl;
    }
    else
    {
        cout << "*\tREGISTER NEW ACCOUNT" << endl;
        cout << "*\t\t\t\t\t\t USERNAME (NoSpace/NoSpecialCharac): "; cin >> UserN;
        cout << "*\t\t\t\t\t\t NEW PASSWORD (NoSpace/NoSpecialCharac): "; cin >> Pass;
        cout << "*\t\t\t\t\t\t\t\t CONFIRM PASSWORD: "; cin >> C_pass;
        while (C_pass != Pass)
        {
            cout << endl;
            cout << "*\tINVALID PASSWORD!!!";
            cout << endl;
            cout << "*\t\t\t\t\t\t\t\t CONFIRM PASSWORD: ";
            cin >> C_pass;
        }
        cout << "\n*\t\t\t\t\t\t ENTER YOUR REGISTERED NAME (LAST NAME, FIRST NAME MI.): ";
        getline(cin >> ws, name);
        cout << "________________________________________________________________________________________________________________________________________________________________________" << endl;
        cout << endl;
    }

    // Information Gathering
    cout << "*\t\t\t\t\t\t Please Answer the Following Questions to Process your Electrical Bill.";
    cout << endl;
    cout << "________________________________________________________________________________________________________________________________________________________________________" << endl;
    cout << "\n*\t\t\t\t\t\t\t\t ADDING INFORMATION" << endl;
    cout << endl;
    for (x = 0; x < 10; x++)
    {
        addrecord(App[x], App_Ans[x], App_count[x], App_HpD[x], watt[x], App_Twatt[x], x);
        cout << endl;
    }
    cout << "________________________________________________________________________________________________________________________________________________________________________" << endl;
    // Deleting Appliances
    cout << "\n*\t\t\t\t\t\t\t\t DELETING INFORMATION" << endl;
    cout << endl;
    cout << "\n*\t\t\t\t\t\t Do you want to Delete Appliances? (Yes/No): "; cin >> D_Ans;
    cout << endl;
    if (D_Ans == "Yes" || D_Ans == "yes" || D_Ans == "YES")
    {
        cout << "*\tType (Yes/No) if you want to Delete the following Appliances: " << endl;
        for (x = 0; x < 10; x++)
        {
            deleterecord(App[x], App_Ans[x], App_count[x], App_HpD[x], App_Twatt[x], x);
        }
    }
    cout << "________________________________________________________________________________________________________________________________________________________________________" << endl;

    // Editing Appliances
    cout << "\n*\t\t\t\t\t\t\t\t EDITTING INFORMATION" << endl;
    cout << endl;
    cout << "\n*\t\t\t\t\t\t Do you want to Edit All Appliances? (Yes/No): "; cin >> E_Ans;
    cout << endl;
    if (E_Ans == "Yes" || E_Ans == "yes" || E_Ans == "YES")
    {
        cout << "*\t\t\t\t\t Do you also want to Edit Deleted Appliances Record?: (Yes/No): "; cin >> DE_Ans;
        cout << "\n*\tInput the new value if you want to Edit the following: " << endl;
        for (x = 0; x < 10; x++)
        {
            editrecord(App[x], DE_Ans, App_count[x], App_HpD[x], App_Twatt[x], watt[x]);
        }
    }
    cout << "========================================================================================================================================================================" << endl;

    // Computation
    for (x = 0; x < 10; x++)
    {
        KwH[x] = (App_Twatt[x] * App_HpD[x])/ 1000;
        KwPerHour = KwPerHour + KwH[x];
        KwHM[x] = KwH[x] * 30;
        KwHourPerMonth = KwHourPerMonth + KwHM[x];
    }
    RatePerMonth = KwHourPerMonth * 11.9112;


    // View
    viewrecord(name, UserN, KwPerHour, KwHourPerMonth, RatePerMonth);

    // Search
    cout << "\n*\t\t\t\t\t\t\t\tSEARCH INFORMATION" << endl;
    cout << endl;
    cout << "*\tDo you want to Search? (Yes/No): "; cin >> S_Ans; cout << endl;
    if (S_Ans == "Yes" || S_Ans == "yes" || S_Ans == "YES")
    {

        while (S_Ans == "yes" || S_Ans == "YES" || S_Ans == "Yes")
        {
            cout << "*\tChoose one of the following Appliances you want to search the calculation: " << endl;
            for (x =0; x <10; x++)
            {
                cout << "*\t" << x+1 << ". " << App[x] << endl;
            }
            cout << "\n*\tEnter the number of your choice: " ; cin >> I_Ans;
            for (x=0; x<= 10; x++)
            {
                if (I_Ans == x+1)
                {
                    searchrecord(App[x], watt[x],App_HpD[x],KwHM[x]);
                }
            }
            cout << endl;
            cout << "*\tDo you want to search again? (Yes/No): "; cin >> S_Ans;
            cout << endl;
        }
    }

    //Payment
    cout << "________________________________________________________________________________________________________________________________________________________________________" << endl;
    cout << "\n*\t\t\t\t\t\t\t\t PAYMENT" << endl;
    cout << endl;
    cout << "*\tDo you want to settle your Electric Bill? (Yes/No): "; cin >> P_Ans;
    if (P_Ans == "Yes" || P_Ans == "yes" || P_Ans == "YES")
    {
        cout << "========================================================================================================================================================================" << endl;
        cout << "*\tTotal Amount " << "\t\t\t\t\t\t\t\t" << "(KwH/Mo/Php):" << "\t\t\t\t\tPhp" << RatePerMonth << endl;
        cout << "========================================================================================================================================================================" << endl;
        RatePerMonthNoCent = RatePerMonth;
        do
        {
            cout << "\n*\tEnter your Payment Cash here (Must Have No Cent): "; cin >> Payment;
            if (Payment >= RatePerMonthNoCent)
            {
                    Change = Payment - RatePerMonthNoCent;
                    cout << "*\tWe received your Payment: Php" << Payment << endl;
                    cout << "*\tHere's your change: Php" << Change << endl;
                    cout << "*\tPAYMENT COMPLETE!!" << endl;
                    RatePerMonthNoCent = 0;
                    break;
            }
            else
            {
                Balance = RatePerMonthNoCent - Payment;
                cout << "*\tYou still have Balance of: Php" << Balance << endl;
                cout << "*\tDo you want to settle your Remaining Balance? (Yes/No): "; cin >> R_Ans;
                RatePerMonthNoCent = Balance;

            }
        }
        while (R_Ans == "Yes" || R_Ans == "yes" || R_Ans == "YES");
    }
    cout << endl;
    cout << "========================================================================================================================================================================" << endl;
    if (RatePerMonthNoCent > 0)
    {
        cout << "\n*\tWarning: Failure to settle the outstanding bill in full on or before the due date shall result to service disconnection."<< endl;
    }
    cout << "========================================================================================================================================================================" << endl;

    return 0;
}
