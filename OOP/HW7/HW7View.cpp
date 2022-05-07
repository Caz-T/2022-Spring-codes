
// HW7View.cpp: CHW7View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "HW7.h"
#endif

#include "HW7Doc.h"
#include "HW7View.h"

#include "Circle_2D.h"
#include "Point_2D.h"
#include "arc.h"
#include "triangle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHW7View

IMPLEMENT_DYNCREATE(CHW7View, CView)

BEGIN_MESSAGE_MAP(CHW7View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHW7View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CHW7View 构造/析构

CHW7View::CHW7View() noexcept
{
	// TODO: 在此处添加构造代码

}

CHW7View::~CHW7View()
{
}

BOOL CHW7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CHW7View 绘图

void CHW7View::OnDraw(CDC* pDC)
{
	CHW7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	HGDIOBJ oldPen = pDC->SelectObject(GetStockObject(DC_PEN));
	HGDIOBJ oldBrush = pDC->SelectObject(GetStockObject(DC_BRUSH));
	pDC->SetDCPenColor(COLORREF(RGB(174, 238, 238)));
	gb_draw_circle(pDC, Circle_2D(200, 200, 150));
	pDC->SetDCPenColor(COLORREF(RGB(255, 0, 0)));
	gb_draw_arc(pDC, arc(140, 200, 50, 60, 120));
	gb_draw_arc(pDC, arc(260, 200, 50, 60, 120));
	gb_draw_arc(pDC, arc(200, 400, 280, 260, 280));
	pDC->SetDCBrushColor(COLORREF(RGB(255, 218, 185)));
	gb_draw_circle(pDC, Circle_2D(200, 190, 10));
	pDC->SelectObject(oldBrush);
	pDC->SetDCPenColor(COLORREF(RGB(255, 218, 185)));
	gb_draw_triangle(pDC, triangle(260, 350, 100, -10));
	gb_draw_triangle(pDC, triangle(140, 350, 100, -170));
	pDC->SelectObject(oldPen);
}


// CHW7View 打印


void CHW7View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CHW7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CHW7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CHW7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CHW7View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CHW7View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CHW7View 诊断

#ifdef _DEBUG
void CHW7View::AssertValid() const
{
	CView::AssertValid();
}

void CHW7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHW7Doc* CHW7View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHW7Doc)));
	return (CHW7Doc*)m_pDocument;
}
#endif //_DEBUG


// CHW7View 消息处理程序
