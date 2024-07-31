#pragma once
#include "EEntity.h"

namespace EX {
	
	class Resource : public Entity // 추상 클래스 메모리 할당 x 상속받아서만 사용해야한다.
	{
	public:
		Resource(enums::eResourceType Type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; //순수가상함수 실제메모리에 할당이 불가능해지는 문법
															//무조건 상속받아서 사용
		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;

	};
	//class Texture : public Resource;
	
	//게임에서 사용되는 데이터들
	//사운드 이미지,정보
}
