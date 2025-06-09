#include "ReportDaily.h"

ReportDaily::ReportDaily() : date(Timee::MYGetCurrentTime()) {}

void ReportDaily::CollectData(Store& store) {
    sales = store.GetSalesByDate(date);
    shipments = store.GetShipmentsByDate(date);
}

void ReportDaily::Write() {
    try
    {
        string filename = GetName() + "/" + Timee::MYGetCurrentTime() + ".json";
        JSONReportWriter jsonWriter(filename);

        json jReport;
        jReport["ReportName"] = CC::CP1251_to_UTF8(GetName());
        jReport["Date"] = CC::CP1251_to_UTF8(date);

        json jSales = json::array();
        for (int i = 0; i < sales.GetSize(); ++i) {
            jSales.push_back(json::parse(sales.Get(i).ToJson()));
        }

        json jShipments = json::array();
        for (int i = 0; i < shipments.GetSize(); ++i) {
            jShipments.push_back(json::parse(shipments.Get(i).ToJson()));
        }

        jReport["Sales"] = jSales;
        jReport["Shipments"] = jShipments;
        jsonWriter.Write(jReport.dump(4));
    }
    catch (const std::exception& e)
    {
        cerr << "Произошла ошибка создания JSONReportWriter: " << endl << e.what() << endl;
        throw;
    }

}

string ReportDaily::GetName() {
    return "DailyReport";
}