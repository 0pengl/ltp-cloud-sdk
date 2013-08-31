/*
 *  PROGRAM:    Word.h
 *              �Դʽ��з�װ
 *              ���еĸ���copy��Ϊ��copy
 *
 *  HISTORY:    2013/8/29   LIU, Yijia
 *              Tidy the project.
 *
 *              2009/1/3    ���л�  THIRD RELEASE
 *              �淶�˸�����д����
 *
 *              2009/12/14  ���л�  SECOND RELEASE
 *              �����˸���set������is����
 *
 *              2009/11/12  ���л�  FIRST RELEASE
 *
 *              zhhan@ir.hit.edu.cn
 *              ��������Ϣ�����о�����
 */
#ifndef __LTPSERVICE_WORD_H__
#define __LTPSERVICE_WORD_H__

#include "tinyxml.h"
#include <stdlib.h>
#include <string>
#include <vector>
#include "LTPOption.h"

namespace ltp {
namespace service {

typedef struct {
    std::string type;
    int beg;
    int end;
} SRL;

class Word {
public:
    /*
     *
     */
    int GetID() const;

    /*
     *
     */
    std::string GetWS() const;

    /*
     *
     */
    std::string GetPOS() const;

    /*
     *
     */
    std::string GetNE() const;

    std::string GetWSD() const;

    int GetParserParent() const;

    std::string GetParserRelation() const;

    bool IsPredicate() const;

    bool GetSRLs(std::vector<SRL> &srls);

    void SetID(int id);

    void SetWS(const std::string& content);

    void SetPOS(const std::string& pos);

    void SetNE(const std::string& ne);

    void SetParser(int parent, const std::string& relation);
private:
    void SetSRLs(const std::vector<SRL> &srls);

public:

    bool HasID() const;

    bool HasWS() const;

    bool HasPOS() const;

    bool HasNE() const;

    bool HasWSD() const;

    bool HasParser() const;

public:

    Word();

    Word(const TiXmlElement& ele);

    Word(const Word& w);

    void operator=( const Word& w);

    ~Word();

private:
    TiXmlElement ele;
};      //  end for class Word

}       //  end for namespace service
}       //  end for namespace ltp

#endif  //  end for define __LTPSERVICE_WORD_H__
