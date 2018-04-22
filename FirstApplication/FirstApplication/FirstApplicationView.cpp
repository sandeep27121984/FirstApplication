
// FirstApplicationView.cpp : implementation of the CFirstApplicationView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FirstApplication.h"
#endif

#include "FirstApplicationDoc.h"
#include "FirstApplicationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFirstApplicationView

IMPLEMENT_DYNCREATE(CFirstApplicationView, CView)

BEGIN_MESSAGE_MAP(CFirstApplicationView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFirstApplicationView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CFirstApplicationView construction/destruction

CFirstApplicationView::CFirstApplicationView()
{
	// TODO: add construction code here

}

CFirstApplicationView::~CFirstApplicationView()
{
}

BOOL CFirstApplicationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFirstApplicationView drawing

void CFirstApplicationView::OnDraw(CDC* /*pDC*/)
{
	CFirstApplicationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CFirstApplicationView printing


void CFirstApplicationView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CFirstApplicationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFirstApplicationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFirstApplicationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CFirstApplicationView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFirstApplicationView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFirstApplicationView diagnostics

#ifdef _DEBUG
void CFirstApplicationView::AssertValid() const
{
	CView::AssertValid();
}

void CFirstApplicationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFirstApplicationDoc* CFirstApplicationView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFirstApplicationDoc)));
	return (CFirstApplicationDoc*)m_pDocument;
}
#endif //_DEBUG


// CFirstApplicationView message handlers
