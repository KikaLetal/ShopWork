#include "ReportBug.h"
void ReportBug::AddError(const Error& error){
	BugReport.Add(error);
}
void ReportBug::Write(){
	try
	{
		string filename = GetName() + "/" + Timee::MYGetCurrentTime() + ".json";
		JSONReportWriter jsonWriter(filename);

		json jReport;
		jReport["ReportName"] = CC::CP1251_to_UTF8(GetName());
		json jErrors = json::array();

		for (int i = 0; i < BugReport.GetSize(); ++i) {
			const Error& err = BugReport.Get(i);
			jErrors.push_back(json::parse(err.ToJson()));
		}

		jReport["Errors"] = jErrors;
		jsonWriter.Write(jReport.dump(4));
	}
	catch (const std::exception& e)
	{
		cerr << "Произошла ошибка создания JSONReportWriter: " << endl << e.what() << endl;
		Error error(GetName(), "Не удалось создать JSONReportWriter");
		AddError(error);
	}

}
string ReportBug::GetName(){
	return "BugReport";
}