#include "Application.h"
#include "Product.h"
#include "Shipment.h"
#include <iostream>

using namespace std;

Application::Application() {
    // �������������
    Store store();

}

Application::~Application() {
    // �������
    OnExit();
}					

void Application::OnStart() {
    try
    {
        store.LoadData();
    }
    catch (const std::exception& e)
    {
        Error error("Store", e.what());
        reportBug.AddError(error);
    }

}

void Application::Run() {
    cout << "����� ���������� � ������� ��������" << endl << endl;
    bool running = true;
    while (running) {
        int comma;
        cout << "1 - ������� ��������\n2 - ���������� ��������\n3 - �������� ����������\n4 - ����������\n5 - �����" << endl << endl;
        while (!(cin >> comma)) {
            cerr << "������: ������� �������� �������, � �� �������.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "���������� �����: ";
        }

        switch (comma) {
        case 1:
            MakeShipment();
            break;
        case 2:
            ProductsOperations();
            break;
        case 3:
            MakeReport();
            break;
        case 4:
            store.SaveData();
            break;
        case 5:
            OnExit();
            running = false;
            break;
        default:
            cout << "������: ����� ������� �� ����������.\n";
        }
    }
    return;
}

void Application::OnExit() {
    store.RemoveExpiredProducts();
    try
    {
        store.SaveData();
    }
    catch (const std::exception& e)
    {
        Error error("Store", e.what());
        reportBug.AddError(error);
    }
    reportBug.Write();
}

void Application::MakeShipment() {
    bool Changing = true;
    while (Changing) {
        string supplierName;
        string date;

        cout << "������� �������� ���������� ��� �������� ������: ";
        cin.ignore(10000, '\n');
        getline(cin, supplierName);
        cout << endl;

        cout << "������� ����� ������ ���, �����, ���� �������� ��� �������� ������ ��� �������: ";
        getline(cin, date);
        cout << endl;

        date = Timee::MYDateConversion(date);
        while (date[0] == '!') {
            cout << date.substr(1) << endl;
            cout << "���������� �����: ";
            getline(cin, date);
            date = Timee::MYDateConversion(date);
            cout << endl;
        }

        List<Product> shipmentProducts;
        bool addingProducts = true;

        while (addingProducts) {
            int quantity;
            double price;
            string ProductName, expdate, Category;
            Dictionary<int, string> Categories = store.GetCategories();
            if (Categories.GetSize() == 0) { //��������� ���
                Product pr = MakeNewProductCard();
                shipmentProducts.Add(pr);
                store.AddProduct(pr);

            }
            else {
                List<string> categ = Categories.DictToList();
                cout << "���������: " << endl;
                for (int i = 0; i < categ.GetSize(); i++) {
                    cout << categ.Get(i) << endl;
                }

                cout << endl;

                cout << "������� ��������� ������: ";
                getline(cin, Category);
                cout << endl;

                if (categ.ContainsValue(Category)) { //ToLow //������ ��� ��������� ����
                    List<Product> prod = store.GetProductsList();

                    cout << "������: " << endl;
                    for (int i = 0; i < prod.GetSize(); i++) {
                        if (prod.Get(i).GetCategory() == Category)
                            cout << prod.Get(i).GetName() << endl;
                    }
                    
                    cout << "������� �������� ������: ";
                    getline(cin, ProductName);
                    cout << endl;

                    bool IsThereNote = false;
                    Product EditableProduct;
                    for (int i = 0; i < prod.GetSize(); i++) {
                        if (prod.Get(i).GetName() == ProductName && prod.Get(i).GetCategory() == Category) {
                            EditableProduct = prod.Get(i);
                            IsThereNote = true;
                        }
                    }

                    if (IsThereNote){ //ToLow //������ ������ ��� ����, ������ ������� ���������
                        cout << "������� ���������� ��� ��������: ";
                        cin >> quantity;
                        cin.ignore(10000, '\n');
                        cout << endl;

                        while (quantity <= 0) {
                            cout << "������: ���������� ������ ���� �������������.\n";
                            cout << "������� ���������� ��� ��������: ";
                            cin >> quantity;
                            cin.ignore(10000, '\n');
                            cout << endl;
                        }

                        cout << "������� ��������� ������: ";
                        cin >> price;
                        cin.ignore(10000, '\n');
                        cout << endl;

                        cout << "������� ����� ������ ���, �����, ���� ��������� ����� ��������: ";
                        getline(cin, expdate);

                        expdate = Timee::MYDateConversion(expdate);
                        while (expdate[0] == '!') {
                            cout << expdate.substr(1) << endl;
                            cout << "���������� �����: ";
                            getline(cin, expdate);
                            expdate = Timee::MYDateConversion(expdate);
                            cout << endl;
                        }

                        cout << endl;
                        Product product = store.ConstructProduct(Category, ProductName, price, quantity, expdate);

                        cout << ShowInfo(product) << endl;

                        int AllRight;
                        cout << "�� �����? ��� - 0, �� - ��� ������: ";
                        cin >> AllRight;
                        cin.ignore(10000, '\n');

                        if (AllRight == 0) {
                            continue;
                        }

                        product.SetID(EditableProduct.GetID());
                        cout << product.GetID() << endl;
                        cout << EditableProduct.GetID() << endl;
                        shipmentProducts.Add(product);
                        product.SetQuantity(product.GetQuantity() + EditableProduct.GetQuantity());
                        store.EditProduct(EditableProduct.GetID(), product);

                    }

                    else { // ������ ��������� ����, �� ��� ������ ������, ������ ��������. 
                        Product pr = MakeNewProductCard(Category, ProductName);
                        shipmentProducts.Add(pr);
                        store.AddProduct(pr);
                    }
                }
                else { //������ ��� ��������� ���, ������ � ������� ��������������, ������ �������� 
                    Product pr = MakeNewProductCard(Category);
                    shipmentProducts.Add(pr);
                    store.AddProduct(pr);
                }

            }

            cout << "�������� ��� ���� �����? (1 - ��, 0 - ���): ";
            int choice;
            while (!(cin >> choice)) {
                cerr << "������� ������������ �������" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "���������� �����: ";


            }
            cin.ignore(10000, '\n');
            cout << endl;
            addingProducts = (choice == 1);
        }

        Shipment ship = store.ConstructShipment(date, shipmentProducts, supplierName);

        cout << ShowInfo(ship) << endl;
        int AllRight;
        cout << "�� �����? ��� - 0, �� - ��� ������: ";
        if ((cin >> AllRight)) {
            if (AllRight == 0) {
                continue;
            }

        }
        store.AddShipment(ship);
        cout << "\n---�������� ������� ������� � ��������� � ���������---\n" << endl;
        Changing = false;
    }
    

    
}

Product Application::MakeNewProductCard(const string& Category, const string& Name){
    int quantity;
    double price;
    string expdate;

    while (true) {
        string category = Category, productName = Name;
        if (category == "") {
            cout << "������� ��������� ������: ";
            getline(cin, category);
            cout << endl;
        }
        if (productName == "") {
            cout << "������� �������� ������: ";
            getline(cin, productName);
            cout << endl;
        }

        cout << "������� ���������� ��� ��������: ";
        cin >> quantity;
        cin.ignore(10000, '\n');
        cout << endl;

        while (quantity <= 0) {
            cout << "������: ���������� ������ ���� �������������.\n";
            cout << "������� ���������� ��� ��������: ";
            cin >> quantity;
            cin.ignore(10000, '\n');
            cout << endl;
        }

        cout << "������� ��������� ������: ";
        cin >> price;
        cin.ignore(10000, '\n');
        cout << endl;

        cout << "������� ����� ������ ���, �����, ���� ��������� ����� ��������: ";
        getline(cin, expdate);

        expdate = Timee::MYDateConversion(expdate);
        while (expdate[0] == '!') {
            cout << expdate.substr(1) << endl;
            cout << "���������� �����: ";
            getline(cin, expdate);
            expdate = Timee::MYDateConversion(expdate);
            cout << endl;
        }

        cout << endl;
        Product product = store.ConstructProduct(category, productName, price, quantity, expdate);

        cout << ShowInfo(product) << endl;

        int AllRight;
        cout << "�� �����? ��� - 0, �� - ��� ������: " << endl;
        cin >> AllRight;
        cin.ignore(10000, '\n');

        if (AllRight != 0) {
            return product;
        }
    }
}

void Application::MakeReport() {
    int rep;
    cout << "����� ������ �� ������ �������?" << endl;
    cout << "0 - ������� ������, 1 - ������ � �������: " << endl;
    while (!(cin >> rep)) {
        cerr << "������: ������� �������� ��������, � �� �������.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "���������� �����: ";
    }
    switch (rep)
    {
    case 0:
        GenerateReport(&reportDaily);
        break;
    case 1:
        GenerateReport(&reportProducts);
        break;
    default:
        cout << "����� ������� �� ����������" << endl;
        break;
    }
}

void Application::ProductsOperations() {
    bool ProductsWork = true;
    while (ProductsWork) {
        int comma;
        cout << "0 - �������� ������\n1 - ���������� ����\n2 - ���������� ������\n3 - ��������� ���������� � ������\n4 - ���������" << endl;
        while (!(cin >> comma)) {
            cerr << "������: ������� �������� ��������, � �� �������.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "���������� �����: ";
        }
        cin.ignore(10000, '\n');
        cout << endl;
        switch (comma) {
        case 0: {
            ShowAllProducts();
            break; 
        }
        case 1: {
            List<Product> products = store.GetProductsList();
            string category, productName;

            ShowAllProducts();

            cout << "������� �������� ������: ";
            getline(cin, productName);
            cout << endl;

            Product CurProduct;
            bool IsFounded = false;
            for (int i = 0; i < products.GetSize(); i++) {
                CurProduct = products.Get(i);

                if (CurProduct.GetName() == productName) {
                    double OverPrice;
                    cout << "������� ������� �� �����: ";
                    cin >> OverPrice;
                    cin.ignore(10000, '\n');
                    cout << endl;

                    IsFounded = true;
                    store.SetOverprice(CurProduct.GetID(), OverPrice);
                    break;
                }

            }
            if(!IsFounded)
                cout << "������ ������ �� ����������" << endl << endl;

            break;
        }
        case 2: {
            List<Product> products = store.GetProductsList();
            string category, productName;
            Product CurProduct;
            bool Realising = true;
            int count;

            ShowAllProducts();

            while (Realising) {
                cout << "������� �������� ������: ";
                getline(cin, productName);
                cout << endl;

                bool IsFounded = false;
                for (int j = 0; j < products.GetSize(); j++) {
                    CurProduct = products.Get(j);

                    if (CurProduct.GetName() == productName) {
                        cout << "������� ���������� ������� ��� �������: ";
                        cin >> count;
                        cin.ignore(10000, '\n');
                        cout << endl;

                        IsFounded = true;
                        store.ReleaseProduct(CurProduct.GetID(), count);
                        break;
                    }

                }
                if (!IsFounded)
                    cout << "������ ������ �� ����������" << endl << endl;

                cout << "����������� ��� ���� �����? (1 - ��, 0 - ���): ";
                int choice;
                while (!(cin >> choice)) {
                    cerr << "������� ������������ �������" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "���������� �����: ";
                }
                cin.ignore(10000, '\n');
                cout << endl;

                Realising = (choice == 1);
            }
            break;
        }
        case 3: {
            List<Product> products = store.GetProductsList();
            string category, productName;

            ShowAllProducts();

            cout << "������� �������� ������: ";
            getline(cin, productName);
            cout << endl;

            Product CurProduct;
            bool IsFounded = false;
            for (int i = 0; i < products.GetSize(); i++) {
                CurProduct = products.Get(i);

                if (CurProduct.GetName() == productName) {
                    Product NewProduct = MakeNewProductCard();
                    cout << endl;

                    IsFounded = true;
                    store.EditProduct(CurProduct.GetID(), NewProduct);
                    break;
                }

            }
            if (!IsFounded)
                cout << "������ ������ �� ����������" << endl << endl;

            break;
        }
        case 4:
            return;
        default:
            cout << "����� ������� �� ����������" << endl;
        }
    }
}

void Application::GenerateReport(Report* report) {

    if (auto daily = dynamic_cast<ReportDaily*>(report)) {
        daily->CollectData(store);
        try
        {
            daily->Write();
        }
        catch (const std::exception& e)
        {
            Error error("������� ������", e.what());
            reportBug.AddError(error);
        }

    }
    else if (auto products = dynamic_cast<ReportProducts*>(report)) {
        products->SetProducts(store);
        try
        {
            products->Write();
        }
        catch (const std::exception& e)
        {
            Error error("������ � ���������", e.what());
            reportBug.AddError(error);
        }
    }
}

void Application::ShowAllProducts() {
    List<Product> products = store.GetProductsList();
    for (int i = 0; i < products.GetSize(); i++) {
        cout << products.Get(i).ToString() << endl << endl;
    }
}
