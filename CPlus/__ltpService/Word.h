/************************************************************************/
/*	
	PROGRAM:	Word.h
				�Դʽ��з�װ
				���еĸ���copy��Ϊ��copy
	HISTORY:	2009/1/3	���л�	THIRD RELEASE
				�淶�˸�����д����
				2009/12/14	���л�	SECOND RELEASE
				�����˸���set������is����
				2009/11/12	���л�	FIRST RELEASE
				zhhan@ir.hit.edu.cn
				��������Ϣ�����о�����
*/
/************************************************************************/

#ifndef _WORD_H_
#define _WORD_H_

#include "tinyxml.h"
//#include "XML4NLP.H"
#include <stdlib.h>
#include <string>
#include <vector>
#include "LTPOption.h"
namespace HIT_IR_LTP{
	typedef struct
	{
		std::string type;
		int beg;
		int end;
	} SRL;

	class Word{
	public:
		int GetID() const;
		std::string GetWS() const;
		std::string GetPOS() const;
		std::string GetNE() const;
		std::string GetWSD() const;
		std::string GetWSDExplanation() const;
		int GetParserParent() const;
		std::string GetParserRelation() const;
		bool IsPredicate() const;
		bool GetSRLs(std::vector<SRL> &srls);

		void SetID(int id);
		void SetWS(const std::string& content);
		void SetPOS(const std::string& pos);
		void SetNE(const std::string& ne);
		void SetWSD(const std::string& wsd, const std::string& explanation);
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

	private:
		TiXmlElement ele;
	};

}
#endif
