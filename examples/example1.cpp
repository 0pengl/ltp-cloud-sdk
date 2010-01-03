/************************************************************************/
/*	
	PROGRAM:	example9
				��SERVICE��LTML���·�װ��Ĳ��Գ���
	HISTORY:	2009/12/23	���л�	FIRST RELEASE
				zhhan@ir.hit.edu.cn
				��������Ϣ�����о�����
*/
/************************************************************************/

#include "LTPData.h"
#include "LTPService.h"
#include "LTML.h"
#include "Word.h"
 
using namespace HIT_IR_LTP;
int main9(){
	LTPService ls("zhhan@ir.hit.edu.cn");

	LTML ltml;
	//*
	vector<Word> wordList;
	Word w1;
	w1.SetWS("��");
	w1.SetPOS("r");
//		w1.SetNE("nr");
	wordList.push_back(w1);

	Word w;
	w.SetWS("��");
	w.SetPOS("v");
	wordList.push_back(w);

	w.SetWS("����");
	w.SetPOS("ns");
	wordList.push_back(w);

	w.SetWS("�찲��");
	w.SetPOS("ns");
	wordList.push_back(w);

	try{

	//	ltml.SetParagraphNumber(2);
		ltml.AddSentence(wordList, 0);
		//*/
		//ltml.SetParagraphNumber(2);
	//	ltml.AddSentence("���Ǻ��л���",0);
	//	ltml.AddSentence("�����Ը����ء�", 0);

		ls.Analyze(ltml, LTPData.WSD,ltml);
		cout<<ltml.GetXMLStr()<<endl;
		int sentNum = ltml.CountSentence();
		for ( int i = 0; i<sentNum; ++i) { 
			string sentCont;
			ltml.GetSentenceContent(sentCont, i);
			cout<< sentCont <<endl;
			//		int wordNum = ltml.CountWordInSentence(i);
			vector<Word> wordList;
			ltml.GetWords(wordList, i);
			for( vector<Word>::iterator iter = wordList.begin(); iter!= wordList.end(); ++iter ){
				if (ltml.HasWS())
				{
					cout<<iter->GetWS()<<"\t"<<iter->GetID();
				}
				if (ltml.HasPOS())
				{
					cout<<"\t"<<iter->GetPOS();
				}
				if(ltml.HasNE())
				{
					cout<<"\t"<<iter->GetNE();
				}
				if(ltml.HasParser())
				{
					cout<<"\t"<<iter->GetParserParent()<<"\t"<<iter->GetParserRelation();
				}
				if(ltml.HasWSD())
				{
					cout<<"\t"<<iter->GetWSD()<<"\t"<<iter->GetWSDExplanation();
				}

				cout<<endl;

				if( iter->IsPredicate() ){
					vector<SRL> srls;
					iter->GetSRLs(srls);
					cout<<srls.size()<<endl;
					for(vector<SRL>::iterator iter = srls.begin(); iter != srls.end(); ++iter){
						cout<<"\t"<<iter->type
							<<"\t"<<iter->beg
							<<"\t"<<iter->end
							<<endl;
					}
				}

			}
		}
	}catch(exception& e){
		std::cerr<<e.what();
	}
	return 0;
}
