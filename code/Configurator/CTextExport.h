// �����Ϳ������á������ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CTextExport ��װ��

class CTextExport : public COleDispatchDriver
{
public:
	CTextExport(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CTextExport(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTextExport(const CTextExport& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ITextExport ����
public:
	BOOL get_IncludeHeader()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_IncludeHeader(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_IncludeLabels()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_IncludeLabels(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_IncludeIndex()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_IncludeIndex(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	VARIANT get_Series()
	{
		VARIANT result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Series(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	void SaveToFile(LPCTSTR FileName)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName);
	}
	VARIANT SaveToStream()
	{
		VARIANT result;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	CString AsString()
	{
		CString result;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	BOOL get_IncludeColors()
	{
		BOOL result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_IncludeColors(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xc9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_UseSeriesFormat()
	{
		BOOL result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_UseSeriesFormat(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xca, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_ValueFormat()
	{
		CString result;
		InvokeHelper(0xcb, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_ValueFormat(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xcb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_TextDelimiter()
	{
		CString result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_TextDelimiter(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// ITextExport ����
public:

};