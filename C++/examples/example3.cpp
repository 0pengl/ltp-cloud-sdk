/************************************************************************/
/*	
	PROGRAM:	example11
				��SERVICE��LTML���·�װ��Ĳ��Գ���
	HISTORY:	2009/1/3	���л�	FIRST RELEASE
				zhhan@ir.hit.edu.cn
				��������Ϣ�����о�����
*/
/************************************************************************/

#include "../__ltpService/LTPOption.h"
#include "../__ltpService/LTPService.h"
#include "../__ltpService/LTML.h"
#include "../__ltpService/Word.h"
 
using namespace HIT_IR_LTP;
int main11(){
	LTPService ls("zhhan@ir.hit.edu.cn");
	LTML ltmlBeg;

	try{
		ls.Analyze(ltmlBeg, LTPOption.WS, "��ҹ���������Ƕ԰����һ��ڶг�������ǻۡ����߽��ĵ�ڤ�롣");		

		vector<Word> wordList;
		ltmlBeg.GetWords(wordList, 0);
		//����ִʽ��
		for( vector<Word>::iterator iter = wordList.begin(); iter!= wordList.end(); ++iter )
		{
			cout<<iter->GetID()<<"\t"<<iter->GetWS()<<endl;
		}
		cout<<endl;

		//������ҹ���롰�������ǡ��ϲ��������Ĵʲ���
		vector<Word> mergeList;
		Word mergeWord;
		mergeWord.SetWS(wordList.at(0).GetWS() + wordList.at(1).GetWS());
		mergeList.push_back(mergeWord);

		for (vector<Word>::iterator iter = wordList.begin()+2; iter != wordList.end(); ++iter)
		{
			Word others;
			others.SetWS(iter->GetWS());
			mergeList.push_back(others);
		}
		LTML ltmlSec;
		ltmlSec.AddSentence(mergeList, 0);
		LTML ltmlOut;
		ls.Analyze(ltmlOut, LTPOption.PARSER, ltmlSec);

		//����ϲ��ִʺ�PARSER���
		cout<<"merge and get parser results."<<endl;
		vector<Word> outList;
		ltmlOut.GetWords(outList,0);
		for (vector<Word>::iterator iter = outList.begin(); iter != outList.end(); ++iter)
		{
			cout<<iter->GetID()<<"\t"<<iter->GetWS()<<"\t"<<iter->GetPOS()<<"\t"<<iter->GetParserParent()<<"\t"<<iter->GetParserRelation()<<endl;				
		}
		cout<<endl;
	}catch(exception& e){
		std::cerr<<e.what();
	}
	return 0;
}
