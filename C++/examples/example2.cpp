/************************************************************************/
/* PROGRAM: example10
 * ��SERVICE��LTML���·�װ��Ĳ��Գ���
 * HISTORY: 2009/12/24  ���л�  FIRST RELEASE
 * zhhan@ir.hit.edu.cn
 * ��������Ϣ�����о�����
 */
/************************************************************************/

#include "LTPOption.h"
#include "LTPService.h"
#include "LTML.h"
#include "Word.h"  

using namespace ltp::service;

int main(){
    LTPService ls("email:token");
    LTML ltml;

    if (!ls.Analyze(LTPOption.ALL,"�Ұ������찲�š�", ltml)) {
        cerr<<"Authorization is denied!"<<endl;
        exit(EXIT_FAILURE);
    }

    int sentNum = ltml.CountSentence();

    for (int i = 0; i < sentNum; ++i) {
        string sentCont;
        ltml.GetSentenceContent(sentCont, i);
        cout << sentCont << endl;
        vector<Word> wordList;

        ltml.GetWords(wordList, i);
        for(vector<Word>::iterator iter = wordList.begin(); iter!= wordList.end(); ++iter){
            cout << iter->GetWS() 
                << "\t" << iter->GetID() 
                << "\t" << iter->GetPOS() 
                << "\t" << iter->GetNE()
                << "\t" << iter->GetParserParent()
                << "\t" << iter->GetParserRelation() 
                << endl;

            if( iter->IsPredicate() ){
                vector<SRL> srls;
                iter->GetSRLs(srls);
                for(vector<SRL>::iterator iter = srls.begin(); iter != srls.end(); ++iter){
                    cout << "\t" << iter->type
                        << "\t" << iter->beg
                        << "\t" << iter->end
                        << endl;
                }
            }
        }
    }

    return 0;
}
