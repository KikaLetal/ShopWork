#include "JSONReportWriter.h"

JSONReportWriter::JSONReportWriter(const string& filename)
{
    int split = filename.rfind("/");
    string directory = filename.substr(0, split);
    if (!fs::exists(JSON_REPORTS_FOLDER + directory)) {
        if (fs::create_directories(JSON_REPORTS_FOLDER + directory)) {
        }
        else {
            std::cerr << "�� ������� ������� �����!" << std::endl;
            throw runtime_error("�� ������� ������� �����!");
        }
    }

    outFile.open(JSON_REPORTS_FOLDER+filename, ios::out | ios::trunc);
}

JSONReportWriter::~JSONReportWriter()
{
    if (outFile.is_open()) {
        outFile.close();
    }
}

void JSONReportWriter::Write(const string& content)
{
    if (outFile.is_open()) {
        outFile << content << endl;
    }
    else {
        throw runtime_error("JSONReportWriter: ���� �� ������ ��� ������");
    }
}