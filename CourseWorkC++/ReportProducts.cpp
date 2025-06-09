#include "ReportProducts.h"

void ReportProducts::SetProducts(Store& store){
    products = store.GetProductsList();
}
void ReportProducts::Write(){
    try
    {
        string filename = GetName() + "/" + Timee::MYGetCurrentTime() + ".json";
        JSONReportWriter jsonWriter(filename);

        json jReport;
        jReport["ReportName"] = CC::CP1251_to_UTF8(GetName());

        json jProducts = json::array();
        for (int i = 0; i < products.GetSize(); ++i) {
            jProducts.push_back(json::parse(products.Get(i).ToJson()));
        }
        jReport["Products"] = jProducts;

        jsonWriter.Write(jReport.dump(4));
    }
    catch (const std::exception& e)
    {
        cerr << "Произошла ошибка создания JSONReportWriter: " << endl << e.what() << endl;
        throw;
        return;
    }
    
}
string ReportProducts::GetName(){
	return "ProductsReport";
}