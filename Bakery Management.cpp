#include <bits/stdc++.h>
using namespace std;
vector<int> v;
map<string, int> m;

class item
{
    string name;
    string unit;
    float price;
    int stock;

public:
    void SetAllValues(item *s);
    void StringCaseChangedToUpperCase(string &x);
    int word_belong_to_string(string &, string &, int, int);
    void PrintWordsWithSubsequenceX(item *, string &, int &);
    void InStock(item *, int, int &);
    int GSTCalculation(item *, int, int);
    void SerialAndQuantityChoiceEnter(item *, int, int &);
    bool ShowItems(string);
};

void item ::SetAllValues(item *s)
{
    s[0].name = "BUTTER COOKIES";
    s[0].unit = "PACK";
    s[0].price = 25;
    s[0].stock = 302;
    s[1].name = "SUGARCANE JUICE";
    s[1].unit = "LITRE";
    s[1].price = 20;
    s[1].stock = 205;
    s[2].name = "CASHEW COOKIES";
    s[2].unit = "PACK";
    s[2].price = 30;
    s[2].stock = 500;
    s[3].name = "CREAM CAKE";
    s[3].unit = "SLICE";
    s[3].price = 22;
    s[3].stock = 602;
    s[4].name = "MILK BISCUITS";
    s[4].unit = "PACK";
    s[4].price = 12;
    s[4].stock = 506;
    s[5].name = "LEMON JUICE";
    s[5].unit = "LITRE";
    s[5].price = 35;
    s[5].stock = 802;
    s[6].name = "BANANA JUICE";
    s[6].unit = "LITRE";
    s[6].price = 40;
    s[6].stock = 203;
    s[7].name = "VEG CASHEW CAKE";
    s[7].unit = "SLICE";
    s[7].price = 18;
    s[7].stock = 562;
    s[8].name = "MANGO JUICE";
    s[8].unit = "LITRE";
    s[8].price = 78;
    s[8].stock = 891;
    s[9].name = "CHOCKLATE CAKE";
    s[9].unit = "SLICE";
    s[9].price = 32;
    s[9].stock = 568;
    s[10].name = "COOKIES (PLAIN)";
    s[10].unit = "PACK";
    s[10].price = 15;
    s[10].stock = 828;
    s[11].name = "CHOCKLATE BISCUITS";
    s[11].unit = "PACK";
    s[11].price = 15;
    s[11].stock = 203;
    s[12].name = "WATER MELLON JUICE";
    s[12].unit = "LITRE";
    s[12].price = 35;
    s[12].stock = 607;
    s[13].name = "ORANGE JUICE";
    s[13].unit = "LITRE";
    s[13].price = 72;
    s[13].stock = 409;
    s[14].name = "PARLE-G BISCUITS";
    s[14].unit = "PACK";
    s[14].price = 10;
    s[14].stock = 781;
    s[15].name = "PLAIN VEG CAKE";
    s[15].unit = "SLICE";
    s[15].price = 20;
    s[15].stock = 882;
    s[16].name = "ORANGE JUICE";
    s[16].unit = "LITRE";
    s[16].price = 60;
    s[16].stock = 556;
    s[17].name = "BUTTER FRUIT CAKE";
    s[17].unit = "SLICE";
    s[17].price = 25;
    s[17].stock = 889;
    s[18].name = "OREO BISCUITS";
    s[18].unit = "PACK";
    s[18].price = 32;
    s[18].stock = 332;
    s[19].name = "APPLE JUICE";
    s[19].unit = "LITRE";
    s[19].price = 82;
    s[19].stock = 547;
}

void item ::StringCaseChangedToUpperCase(string &x)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] >= 'a' && x[i] <= 'z')
        {
            x[i] = x[i] - 'a' + 'A';
        }
    }
}

int item ::word_belong_to_string(string &s, string &x, int k, int t)
{
    int dp[k + 1][t + 1];
    memset(dp, -1, sizeof(dp));
    if (k == 0 || t == 0)
        return 0;
    if (dp[k][t] != -1)
        return dp[k][t];
    if (s[k - 1] == x[t - 1])
    {
        return dp[k][t] = 1 + word_belong_to_string(s, x, k - 1, t - 1);
    }
    return dp[k][t] = max(word_belong_to_string(s, x, k - 1, t), word_belong_to_string(s, x, k, t - 1));
}

void item ::PrintWordsWithSubsequenceX(item *s, string &x, int &z)
{
    for (int i = 0; i < 20; i++)
    {
        int k = word_belong_to_string((s[i].name), x, (s[i].name).size(), x.size());
        if (k == x.size())
        {
            z++;
            if (z < 10)
            {
                cout << " " << z << " : " << s[i].name;
                v.push_back(i);
                for (int d = 0; d < 20 - ((s[i].name).size()); d++)
                {
                    cout << " ";
                }
                cout << "--- Rs." << s[i].price << ".00 per " << s[i].unit << endl;
            }
            else
            {
                cout << z << " : " << s[i].name;
                v.push_back(i);
                for (int d = 0; d < 20 - (s[i].name).size(); d++)
                {
                    cout << " ";
                }
                cout << "--- Rs." << s[i].price << ".00 per " << s[i].unit << endl;
            }
        }
    }
    if (z == 0)
    {
        cout << "Sorry, no such item is found..." << endl;
    }
}

void item ::InStock(item *s, int a, int &c)
{
    while (s[v[a - 1]].stock < c)
    {
        cout << "\nWe are really Sorry To inform that we dont have that much stock" << endl;
        cout << "We have " << s[v[a - 1]].stock << " Stocks of " << s[v[a - 1]].name << endl;
        cout << "We can Provide you that amount" << endl;
        cout << "Enter the new Quantity You want to have: ";
        cin >> c;
    }
}

int item ::GSTCalculation(item *s, int a, int c)
{
    m[s[v[a - 1]].name] += c;
    float r = c * (s[v[a - 1]].price) * (1.1);
    int k = r * 10;
    if (((k) % 10) >= 5)
        r = r + 1;
    return r;
}

void item ::SerialAndQuantityChoiceEnter(item *s, int z, int &ans)
{
    item ob;
    if (z > 0)
    {
        int a, c;
        cout << "Enter a Choice from above Serial numbers: ";
        cin >> a;
        while (a > z)
        {
            cout << "Warning !!!\n***You have entred an invalid choice***\nRenter your Choice : ";
            cin >> a;
        }
        cout << "Enter the Quantity you need to have: ";
        cin >> c;
        ob.InStock(s, a, c);
        ans += ob.GSTCalculation(s, a, c);
    }
}

bool item ::ShowItems(string c)
{
    if (c == "YES")
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    item ob, s[21];
    int ans = 0;
    ob.SetAllValues(s);
    string userentered = "Yes"; //,show;
    while (userentered[0] == 'Y')
    {
        cout << "\n***Welcome to Our Backery***" << endl;
        cout << "We have different varities of 'Cookies, Biscuits, Cake, Juice' at our backery" << endl;
        int z = 0;
        // cout<<"\nDo You want to see all items ? (Enter yes/no): ";
        // cin>>show;
        // ob.StringCaseChangedToUpperCase(show);
        // if(ob.ShowItems(show)){
        // show.clear();
        // ob.PrintWordsWithSubsequenceX(s,show,z);
        // }
        // cin.ignore();
        z = 0;
        cout << "Enter any subsequence (in any case) of the above names you will get their details" << endl;
        cout << "What Do you want to have: ";
        string x;
        getline(cin, x);
        ob.StringCaseChangedToUpperCase(x);

        cout << "Items found matching with your keyword:" << endl;
        ob.PrintWordsWithSubsequenceX(s, x, z);
        ob.SerialAndQuantityChoiceEnter(s, z, ans);
        cout << "\nDo You Want to have More item ?";
        cout << "\nEnter Yes/No : ";
        cin >> userentered;
        cin.ignore();
        ob.StringCaseChangedToUpperCase(userentered);
        v.clear();
    }
    cout << "\nYou Have ordered : " << endl;
    cout << "Product Name      Quantity" << endl;
    for (auto it : m)
    {
        cout << it.first;
        for (int d = 0; d < 20 - (it.first).size(); d++)
        {
            cout << " ";
        }
        cout << it.second << endl;
    }
    cout << "Total cost to be paid (with GST) = Rs. " << ans << "." << endl;
    cout << "\nThanks For Placing Order" << endl;
    cout << "\nProvide a Minor detais " << endl;
    string name, address, pincode;
    cout << "Enter Your full Name : ";
    getline(cin, name);
    cout << "Enter Shipping Address : ";
    getline(cin, address);
    cout << "Enter Pincode of Your area : ";
    cin >> pincode;
    cout << "\nYour Order Is placed Succesfully" << endl;
    cout << "Details of the order \n";
    cout << "Placed By : " << name << "\nShipping Address : " << address << "\nPincode : " << pincode << endl;
    cout << "\nYou Have ordered : " << endl;
    cout << "Product Name      Quantity" << endl;
    for (auto it : m)
    {
        cout << it.first;
        for (int d = 0; d < 20 - (it.first).size(); d++)
        {
            cout << " ";
        }
        cout << it.second << endl;
    }
    cout << "Total cost to be paid (with GST) = Rs. " << ans << "." << endl;
    cout << "\nYour will have your order in 1 hour" << endl;
    cout << "Do Rate us in the scale of 1-5 (Where 5 means Excellent and 1 means Poor) : " << endl;
    int feedbackpoint;
    cin >> feedbackpoint;
    cout << "Thanks For Your valuable Feedback, We are happy to serve you" << endl;

    if (feedbackpoint < 3)
    {
        cout << "We would like to hear that how could we improve our service : ";
        string improvementSuggestion;
        cin.ignore();
        getline(cin,improvementSuggestion);
    }
    else if (feedbackpoint == 5)
    {
        cout << "We will be greatfull to maintain rating at this stage and improve upto more extent in future";
    }
    else
    {
        cout << "We would work hard to take the rating up to 5";
    }
    return 0;
}
