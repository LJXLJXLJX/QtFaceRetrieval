#include "utils.h"
#include <io.h>
#include <time.h>
#include <random>


using namespace std;

void getFiles(std::string path, std::vector<std::string>& files)
{
	//文件句柄  
	intptr_t hFile = 0;
	//文件信息  
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之  
			//如果不是,加入列表  
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFiles(p.assign(path).append("/").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(fileinfo.name);
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

int API_TimeToString(const time_t & timeData, std::string &DateStr)
{
	char chTmp[15];
	memset(chTmp, 0, sizeof(chTmp));

	struct tm *p;
	p = localtime(&timeData);

	p->tm_year = p->tm_year + 1900;

	p->tm_mon = p->tm_mon + 1;


	_snprintf(chTmp, sizeof(chTmp), "%04d-%02d-%02d",
		p->tm_year, p->tm_mon, p->tm_mday);

	DateStr = chTmp;
	return 0;
}

string randomSerise()
{
	string res;
	const string table = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	static default_random_engine e(time(0));
	static uniform_int_distribution<unsigned> u(0, table.size() - 1);
	for (int i = 0; i < 10; ++i)
	{
		res.push_back(table[u(e)]);
	}


	return res;
}
