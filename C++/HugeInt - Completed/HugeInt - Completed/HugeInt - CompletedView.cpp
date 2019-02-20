
// HugeInt - CompletedView.cpp : implementation of the CHugeIntCompletedView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "HugeInt - Completed.h"
#endif

#include "HugeInt - CompletedDoc.h"
#include "HugeInt - CompletedView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHugeIntCompletedView

IMPLEMENT_DYNCREATE(CHugeIntCompletedView, CView)

BEGIN_MESSAGE_MAP(CHugeIntCompletedView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHugeIntCompletedView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CHugeIntCompletedView construction/destruction

CHugeIntCompletedView::CHugeIntCompletedView()
{
	// TODO: add construction code here

}

CHugeIntCompletedView::~CHugeIntCompletedView()
{
}

BOOL CHugeIntCompletedView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CHugeIntCompletedView drawing

void CHugeIntCompletedView::OnDraw(CDC* /*pDC*/)
{
	CHugeIntCompletedDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CHugeIntCompletedView printing


void CHugeIntCompletedView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CHugeIntCompletedView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHugeIntCompletedView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHugeIntCompletedView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CHugeIntCompletedView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CHugeIntCompletedView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CHugeIntCompletedView diagnostics

#ifdef _DEBUG
void CHugeIntCompletedView::AssertValid() const
{
	CView::AssertValid();
}

void CHugeIntCompletedView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHugeIntCompletedDoc* CHugeIntCompletedView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHugeIntCompletedDoc)));
	return (CHugeIntCompletedDoc*)m_pDocument;
}
#endif //_DEBUG


// CHugeIntCompletedView message handlers
