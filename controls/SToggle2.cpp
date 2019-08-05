#include "StdAfx.h"
#include "SToggle2.h"

namespace SOUI
{
	SToggle2::SToggle2(void)
	{
	}

	SToggle2::~SToggle2(void)
	{
	}

	void SToggle2::OnPaint(IRenderTarget *pRT)
	{
		m_pSkin->DrawByIndex(pRT, GetClientRect(),  (GetToggle())?1:0);
	}

	//CSize SToggle2::GetDesiredSize(LPCRECT pRcContainer)
	//{
	//	return m_pSkin1->GetSkinSize();
	//}

}
