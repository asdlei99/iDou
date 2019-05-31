/**
 * Copyright (C) 2014-2050 SOUI团队
 * All rights reserved.
 *
 * @file       SHeaderCtrlEx.h
 * @brief
 * @version    v1.0
 * @author     008
 * @date       2017-01-07
 *
 * Describe
 */
#pragma once


#include "control/SHeaderCtrl.h"
namespace SOUI
{
	/**
	 * @class     SHeaderCtrlEx
	 * @brief     表头控件
	 *
	 * Describe   表头控件
	 */
	class SHeaderCtrlEx : public SHeaderCtrl
	{
		SOUI_CLASS_NAME(SHeaderCtrlEx, L"header2")
	public:
		SHeaderCtrlEx(void);
		bool isViewWidthMatchParent() const;
		//第二个参数表明是否拉伸
		void Move(LPCRECT prect, bool _newSize);

		SOUI_ATTRS_BEGIN()
			ATTR_INT(L"matchParent", m_bMatchParent, FALSE)
		SOUI_ATTRS_END()

	protected:
		//添加一个函数支持同父窗口变化自身大小，些时和width按照它们的值等比例化分

		void UpdataWidth();
		void OnSize(UINT nType, CSize size);

		virtual BOOL CreateChildren(pugi::xml_node xmlNode);
		virtual BOOL OnSetCursor(const CPoint& pt);
		
		SOUI_MSG_MAP_BEGIN()
			MSG_WM_SIZE(OnSize)
		SOUI_MSG_MAP_END()

		SArray<int> m_widItems; /**< 列表项集合 */
		BOOL m_bMatchParent;
		bool m_bNewSize;
	};
}//end of namespace SOUI
