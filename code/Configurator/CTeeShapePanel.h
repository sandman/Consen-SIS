// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CTeeShapePanel 包装类

class CTeeShapePanel : public COleDispatchDriver
{
public:
	CTeeShapePanel(){} // 调用 COleDispatchDriver 默认构造函数
	CTeeShapePanel(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTeeShapePanel(const CTeeShapePanel& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// ITeeShapePanel 方法
public:
	unsigned long get_Color()
	{
		unsigned long result;
		InvokeHelper(0x6c, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, NULL);
		return result;
	}
	void put_Color(unsigned long newValue)
	{
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(0x6c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_Font()
	{
		LPDISPATCH result;
		InvokeHelper(0x68, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Gradient()
	{
		LPDISPATCH result;
		InvokeHelper(0x65, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_ShadowSize()
	{
		long result;
		InvokeHelper(0x3f4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_ShadowSize(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3f4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	unsigned long get_ShadowColor()
	{
		unsigned long result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, NULL);
		return result;
	}
	void put_ShadowColor(unsigned long newValue)
	{
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(0x66, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_Transparent()
	{
		BOOL result;
		InvokeHelper(0x3f5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Transparent(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x3f5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_ShapeStyle()
	{
		long result;
		InvokeHelper(0x67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_ShapeStyle(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x67, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Transparency()
	{
		long result;
		InvokeHelper(0x7e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Transparency(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x7e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_ShapeBounds()
	{
		LPDISPATCH result;
		InvokeHelper(0x85, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_Bevel()
	{
		long result;
		InvokeHelper(0x139, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Bevel(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x139, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_BevelWidth()
	{
		long result;
		InvokeHelper(0x13a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_BevelWidth(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x13a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void ShowEditorShape()
	{
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	LPDISPATCH get_Shadow()
	{
		LPDISPATCH result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_RoundSize()
	{
		long result;
		InvokeHelper(0xcb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_RoundSize(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xcb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_Pen()
	{
		LPDISPATCH result;
		InvokeHelper(0xcc, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Picture()
	{
		LPDISPATCH result;
		InvokeHelper(0xcd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void Show()
	{
		InvokeHelper(0xce, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Hide()
	{
		InvokeHelper(0xcf, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL get_CustomPosition()
	{
		BOOL result;
		InvokeHelper(0xdb, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_CustomPosition(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xdb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Left()
	{
		long result;
		InvokeHelper(0xd2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Left(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xd2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Top()
	{
		long result;
		InvokeHelper(0xd3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Top(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xd3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_Frame()
	{
		LPDISPATCH result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	// ITeeShapePanel 属性
public:

};
