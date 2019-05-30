#include "stdafx.h"
#include "SHeaderCtrlEx.h"


namespace SOUI
{


    SHeaderCtrlEx::SHeaderCtrlEx(void)
		:m_bMatchParent(FALSE)
    {       
    }  

	bool SHeaderCtrlEx::isViewWidthMatchParent() const
	{
		return TRUE == m_bMatchParent;
	}

	void SHeaderCtrlEx::UpdataWidth()
	{
		//更新不同步
		SASSERT(m_widItems.GetCount() == m_arrItems.GetCount());
		int totalWidth = 0;
		for (int i = 0; i < m_widItems.GetCount(); i++)
		{
			totalWidth += m_widItems[i];
		}
		int parentViewWid = GetWindowRect().Width();
		int remainingWid = parentViewWid;
		int nozeroPos = 0;//找到第一个不为0的项
		for (int i = 0; i < m_arrItems.GetCount(); i++)
		{
			//跳过为0的项
			if (m_widItems[i] == 0)
				continue;
			nozeroPos = i;
			break;
		}
		for (int i = m_arrItems.GetCount() - 1; i > nozeroPos; i--)
		{
			//跳过为0的项
			if (m_widItems[i] == 0)
				continue;
			int itemwid = m_widItems[i] * parentViewWid / totalWidth;
			m_arrItems[i].cx.fSize = itemwid;
			remainingWid -= itemwid;
		}
		//因为除法不一定能整除，把最后余下的全给第一个不为0的子项
		m_arrItems[nozeroPos].cx.fSize = remainingWid;
	}

	void SHeaderCtrlEx::OnSize(UINT nType, CSize size)
	{
		if (isViewWidthMatchParent())
			UpdataWidth();
	}

	// 	BOOL SHeaderCtrlEx::CreateChildren( pugi::xml_node xmlNode )
//     {
//         pugi::xml_node xmlItems=xmlNode.child(L"items");
//         if(!xmlItems) return FALSE;
//         pugi::xml_node xmlItem=xmlItems.child(L"item");
//         int iOrder=0;
//         while(xmlItem)
//         {
//             SHDITEM item={0};
//             item.mask=0xFFFFFFFF;
//             item.iOrder=iOrder++;
//             SStringW strText = xmlItem.text().get();
//             strText.TrimBlank();
//             strText = tr(GETSTRING(strText));
//             SStringT strText2 = S_CW2T(strText);
//             item.pszText=_tcsdup(strText2);
//             item.cchTextMax=strText2.GetLength();
// 			if (isViewWidthMatchParent())
// 			{
// 				int cx = xmlItem.attribute(L"width").as_int(50);
// 				m_widItems.InsertAt(m_arrItems.GetCount(), cx);
// 			}
// 			else
// 			{
// 				item.cx = xmlItem.attribute(L"width").as_int(50);
// 			}
//             item.lParam=xmlItem.attribute(L"userData").as_uint(0);
//             item.stFlag=(SHDSORTFLAG)xmlItem.attribute(L"sortFlag").as_uint(ST_NULL);
//             m_arrItems.InsertAt(m_arrItems.GetCount(),item);
//             xmlItem=xmlItem.next_sibling(L"item");
//         }
// 		if (isViewWidthMatchParent())
// 		{
// 			m_bFixWidth = TRUE;
// 		}		
//         return TRUE;
//     }
	BOOL SHeaderCtrlEx::CreateChildren(pugi::xml_node xmlNode)
	{
		pugi::xml_node xmlItems = xmlNode.child(L"items");
		if (xmlItems)
			xmlItems.set_userdata(1);
		SWindow::CreateChildren(xmlNode);
		if (!xmlItems) return FALSE;
		pugi::xml_node xmlItem = xmlItems.child(L"item");
		LockUpdate();

		while (xmlItem)
		{
			SStringW strText = xmlItem.text().get();
			strText.TrimBlank();
			strText = tr(GETSTRING(strText));
			SStringT strText2 = S_CW2T(strText);
			int cx = xmlItem.attribute(L"width").as_int(50);
			if (isViewWidthMatchParent())
			{
				m_widItems.InsertAt(m_arrItems.GetCount(), cx);
			}
			LPARAM lParam = xmlItem.attribute(L"userData").as_uint(0);
			SHDSORTFLAG stFlag = (SHDSORTFLAG)xmlItem.attribute(L"sortFlag").as_uint(ST_NULL);

			InsertItem(-1, strText2, cx, stFlag, lParam);

			xmlItem = xmlItem.next_sibling(L"item");
		}
		UnlockUpdate();
		return TRUE;
	}
	BOOL SHeaderCtrlEx::OnSetCursor(const CPoint & pt)
	{
		if (m_bFixWidth) return FALSE;
		DWORD dwHit = HitTest(pt);
		if (HIWORD(dwHit) == LOWORD(dwHit))
			return SWindow::OnSetCursor(pt);;
		HCURSOR hCursor = GETRESPROVIDER->LoadCursor(IDC_SIZEWE);
		SetCursor(hCursor);
		return TRUE;
	}
	 
}//end of namespace SOUI
