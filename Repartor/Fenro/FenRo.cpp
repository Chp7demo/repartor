#include "FenRo.h"




using namespace std; 

FenRo::FenRo() :QWidget()
{

    fenRoDes=new FenRoDes();

    fenRoBut=new FenRoBut();
    hLayout=new QHBoxLayout();

    hLayout->addWidget(fenRoDes);
    hLayout->addWidget(fenRoBut);
    hLayout->setStretchFactor(fenRoDes,80);
    hLayout->setStretchFactor(fenRoBut,1);

    this->setLayout(hLayout);

    connect(fenRoBut,SIGNAL(aj_mode(ViewMode)),fenRoDes,SLOT(setMode(ViewMode)));

    connect(fenRoDes,SIGNAL(modif_cell(int,Pos)),this,SLOT(emetre_modif_cell(int,Pos)));
    connect(fenRoDes,SIGNAL(supr_cell(int)),this,SLOT(emetre_supr_cell(int)));
    connect(fenRoDes,SIGNAL(add_cell(Pos)),this,SLOT(emetre_add_cell(Pos)));
    connect(fenRoDes,SIGNAL(add_cpl(int,int)),this,SLOT(emetre_add_cpl(int,int)));
    connect(fenRoDes,SIGNAL(supr_cpl(int,int)),this,SLOT(emetre_supr_cpl(int,int)));

}


FenRoDes::FenRoDes() :QWidget()
{
    setMinimumSize(700,400);
    container=new QWidget(this);
    scroll_area_2=new QScrollArea;
    scroll_area_2->setWidget(container);
    scroll_area_2->setWidgetResizable(true);

    container->setMinimumSize(4000,4000);
    graphScene =new QGraphicsScene(QRectF(0,0,4000,4000),this);
    graphView = new MaGraphicsView(graphScene,container);

    //indispensable: ==============================================
    graphView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //===============================================================

    QHBoxLayout *layout =new QHBoxLayout;
    layout->addWidget(graphView);
    layout->setContentsMargins(0,0,0,0);
    container->setLayout(layout);

    QHBoxLayout *layout_2 =new QHBoxLayout;
    layout_2->addWidget(scroll_area_2);
    this->setLayout(layout_2);
    connect(graphView,SIGNAL(resize(qreal)),this,SLOT(resize(qreal)));

    connect(graphView,SIGNAL(modif_cell(int,Pos)),this,SLOT(emetre_modif_cell(int,Pos)));
    connect(graphView,SIGNAL(supr_cell(int)),this,SLOT(emetre_supr_cell(int)));
    connect(graphView,SIGNAL(add_cell(Pos)),this,SLOT(emetre_add_cell(Pos)));
    connect(graphView,SIGNAL(add_cpl(int,int)),this,SLOT(emetre_add_cpl(int,int)));
    connect(graphView,SIGNAL(supr_cpl(int,int)),this,SLOT(emetre_supr_cpl(int,int)));

}



void FenRoDes::setMode(ViewMode vm)
{
    graphView->setMode(vm);
}


MaGraphicsView::MaGraphicsView(QGraphicsScene * scene,QWidget *parent)
    :QGraphicsView(scene,parent)
{

    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    wicell_temp=NULL;
    wiL_temp=NULL;
    ptr_wiC_a=NULL;
    ptr_wiC_b=NULL;
    ptr_wiC_c=NULL;
    ptr_wiC_d=NULL;
    ptr_wiC_e=NULL;
    ptr_wiC_f=NULL;
    ptr_wiC_g=NULL;

    ptr_li_a=NULL;
    ptr_li_b=NULL;
    ptr_li_c=NULL;

    MINIMAL_WIDTH=20;
    MINIMAL_HEIGTH=20;
    MAXIMAL_WIDTH=300;
    MAXIMAL_HEIGTH=300;

    deplacement=false;
    move_liaison=false;
    mode=ViewMode::NOMODE;

    connect(this,SIGNAL(rotation(int)),this,SLOT(effectuer_rot(int)));//??
}



MonBout::MonBout() :QPushButton()
{
    setFixedSize(70,60);
    m_mode=ViewMode::NOMODE;
    connect(this,SIGNAL(clicked()),this,SLOT(envoyer_click()));
}



void MonBout::envoyer_click()
{
    emit mon_clicked(this);
}



ViewMode MonBout::mode()
{
    return m_mode;
}


void  MonBout::setMode(ViewMode md)
{
    m_mode=md;
}


FenRoBut::FenRoBut() :QWidget()
{
    setMinimumSize(90,400);

    vLayout=new QVBoxLayout();

    MonBout *butCell=new MonBout();
    butCell->setText("Cellule");
    butCell->setMode(ViewMode::CELL);
    butCell->setCheckable(true);

    MonBout *butCpl=new MonBout();
    butCpl->setText("Joindre");
    butCpl->setMode(ViewMode::CPL);
    butCpl->setCheckable(true);

    MonBout *butCopie=new MonBout();
    butCopie->setText("Copier");
    butCopie->setMode(ViewMode::COPIE);
    butCopie->setCheckable(true);

    MonBout *butRot=new MonBout();
    butRot->setText("Rotation");
    butRot->setMode(ViewMode::ROT);
    butRot->setCheckable(true);


    MonBout *butSupr=new MonBout();
    butSupr->setText("Suprimer");
    butSupr->setMode(ViewMode::SUPRR);
    butSupr->setCheckable(true);


    list_but<<butCell<<butCpl<<butCopie<<butRot<<butSupr;

    vLayout->addWidget(butCell);
    vLayout->addWidget(butCpl);
    vLayout->addWidget(butCopie);
    vLayout->addWidget(butRot);
    vLayout->addWidget(butSupr);

    this->setLayout(vLayout);

    connect(butCell,SIGNAL(mon_clicked(MonBout*)),this, SLOT(aj_but(MonBout*)));
    connect(butCpl,SIGNAL(mon_clicked(MonBout*)),this, SLOT(aj_but(MonBout*)));
    connect(butRot,SIGNAL(mon_clicked(MonBout*)),this, SLOT(aj_but(MonBout*)));
    connect(butSupr,SIGNAL(mon_clicked(MonBout*)),this, SLOT(aj_but(MonBout*)));
    connect(butCopie,SIGNAL(mon_clicked(MonBout*)),this, SLOT(aj_but(MonBout*)));

}


void FenRoBut::aj_but(MonBout *bout) 
{
    if(bout->isChecked())
    {
        uncheck_others(bout);
        emit aj_mode(bout->mode());
    }
    else{emit aj_mode(ViewMode::NOMODE);}
}


void FenRoBut::uncheck_others(MonBout *bout)
{
    for(int i=0;i<list_but.size();i++)
    {
        if(list_but.at(i)!= bout)list_but.at(i)->setChecked(false);
    }

}


void MaGraphicsView::mousePressEvent(QMouseEvent *event)
{
    event->accept();
    switch(mode)
    {
    case ViewMode::NOMODE:mousePressEvent_NOMODE(event);
        break;
    case ViewMode::CELL:mousePressEvent_CELL(event);
        break;
    case ViewMode::DES_CELL:mousePressEvent_DES_CELL(event);
        break;
    case ViewMode::CPL:mousePressEvent_CPL(event);
        break;
    case ViewMode::BAR_CPL:mousePressEvent_BAR_CPL(event);
        break;
    case ViewMode::COPIE:mousePressEvent_COPIE(event);
        break;
    case ViewMode::SUPRR:mousePressEvent_SUPRR(event);
        break;
    case ViewMode::ROT:mousePressEvent_ROT(event);
        break;
    }
}


void MaGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    event->accept();

    switch(mode)
    {
    case ViewMode::NOMODE:mouseMoveEvent_NOMODE(event);
        break;
    case ViewMode::CELL:mouseMoveEvent_CELL(event);
        break;
    case ViewMode::DES_CELL:mouseMoveEvent_DES_CELL(event);
        break;
    case ViewMode::CPL:mouseMoveEvent_CPL(event);
        break;
    case ViewMode::BAR_CPL:mouseMoveEvent_BAR_CPL(event);
        break;
    case ViewMode::COPIE:mouseMoveEvent_COPIE(event);
        break;
    case ViewMode::SUPRR:mouseMoveEvent_SUPRR(event);
        break;
    case ViewMode::ROT:mouseMoveEvent_ROT(event);
        break;
    }
}


void MaGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    event->accept();

    switch(mode)
    {
    case ViewMode::NOMODE:mouseReleaseEvent_NOMODE(event);
        break;
    case ViewMode::CELL:mouseReleaseEvent_CELL(event);
        break;
    case ViewMode::DES_CELL:mouseReleaseEvent_DES_CELL(event);
        break;
    case ViewMode::CPL:mouseReleaseEvent_CPL(event);
        break;
    case ViewMode::BAR_CPL:mouseReleaseEvent_BAR_CPL(event);
        break;
    case ViewMode::COPIE:mouseReleaseEvent_COPIE(event);
        break;
    case ViewMode::SUPRR:mouseReleaseEvent_SUPRR(event);
        break;
    case ViewMode::ROT:mouseReleaseEvent_ROT(event);
        break;
    }
}


void  MaGraphicsView::mouseDoubleClickEvent(QMouseEvent *event)
{
    event->accept();

    switch(mode)
    {
    case ViewMode::NOMODE:mouseDoubleClickEvent_NOMODE(event);
        break;
    case ViewMode::CELL:mouseDoubleClickEvent_CELL(event);
        break;
    case ViewMode::DES_CELL:mouseDoubleClickEvent_DES_CELL(event);
        break;
    case ViewMode::CPL:mouseDoubleClickEvent_CPL(event);
        break;
    case ViewMode::BAR_CPL:mouseDoubleClickEvent_BAR_CPL(event);
        break;
    case ViewMode::COPIE:mouseDoubleClickEvent_COPIE(event);
        break;
    case ViewMode::SUPRR:mouseDoubleClickEvent_SUPRR(event);
        break;
    case ViewMode::ROT:mouseDoubleClickEvent_ROT(event);
        break;

    }
}


//================================NOMODE==========================================
//PRESS.............................................................................
void MaGraphicsView::mousePressEvent_NOMODE(QMouseEvent *event)
{
}
//MOVE..................................................................................
void MaGraphicsView::mouseMoveEvent_NOMODE(QMouseEvent *event)
{
}
//RELEASE.........................................................................
void MaGraphicsView::mouseReleaseEvent_NOMODE(QMouseEvent *event)
{
}
//DBL CLICK.........................................................................
void  MaGraphicsView::mouseDoubleClickEvent_NOMODE(QMouseEvent *event)
{
}

//================================CELL=======================================================
//PRESS.................................................................................
void MaGraphicsView::mousePressEvent_CELL(QMouseEvent *event)
{
    if(event->button()== Qt::LeftButton)
    {

        p_1=event->pos();
        p_3=p_1;
        ptr_wiC_g=find_cell(p_1);
        if(ptr_wiC_g!=NULL)
        {
            pos_1=ptr_wiC_g->pos();
            ptr_wiC_g->setZValue(1);
            QColor coul;
            coul.setRgb(255,236,139);

            ptr_wiC_g->set_couleur(coul);

            setCursor(Qt::ClosedHandCursor);
            deplacement=true;

            //si liaison
            ptr_li_c=ptr_wiC_g->get_ptr_li();
            if(ptr_li_c!=NULL)
            {
                move_liaison=true;

                ctr=ptr_wiC_g->get_centre();

                //point autre bout
                ptr_wiC_e=ptr_wiC_g->get_ptr_cell_li();
                ptr_wiC_e->set_ptr_li(NULL);
                ctr_2=ptr_wiC_e->get_centre();

                this->scene()->removeItem(ptr_li_c);
                list_widgLi.removeOne(ptr_li_c);
                wiL_temp=new WidgLi(ctr,ctr_2);
                wiL_temp->setZValue(2);
                this->scene()->addItem(wiL_temp);

            }

        }
        else
        {
            setMode(ViewMode::DES_CELL);
        }
    }
}


//MOVE........................................................................................
void MaGraphicsView::mouseMoveEvent_CELL(QMouseEvent *event)
{

    p_2=event->pos();
    if(deplacement)
    {

        setCursor(Qt::ClosedHandCursor);
        pos_1.setX(pos_1.x()+(p_2.x()-p_1.x()));
        pos_1.setY(pos_1.y()+(p_2.y()-p_1.y()));

        //si liasion
        if(move_liaison)
        {
            //le nouveau:
            ctr.setX(ctr.x()+(p_2.x()-p_1.x()));
            ctr.setY(ctr.y()+(p_2.y()-p_1.y()));

            this->scene()->removeItem(wiL_temp);
            wiL_temp=new WidgLi(ctr,ctr_2);
            wiL_temp->setZValue(2);
            this->scene()->addItem(wiL_temp);

        }

        ptr_wiC_g->setPos(pos_1);
        QColor coul;
        coul.setRgb(255,236,139);

        ptr_wiC_g->set_couleur(coul);

        p_1=p_2;
        update();

    }
    else
    {
        //si bouton pas pressé et seulement entree et sortie pr pas gaspiller de la memoire TODO
        ptr_wiC_g=find_cell(p_2);

        if (ptr_wiC_g!=NULL)
        {
            setCursor(Qt::OpenHandCursor);
        }
        else
        {
            setCursor(Qt::ArrowCursor);
        }
    }
}


//RELEASE..................................................................................
void MaGraphicsView::mouseReleaseEvent_CELL(QMouseEvent *event)
{
    if(deplacement)
    {
        //mal codé...
        p_2=event->pos();
        pos_1.setX(pos_1.x()+(p_2.x()-p_1.x()));
        pos_1.setY(pos_1.y()+(p_2.y()-p_1.y()));

        ptr_wiC_g->setPos(pos_1);
        QRectF rectf=ptr_wiC_g->get_rect_eff();//de l'ancienne position
        QPainterPath path_shape=ptr_wiC_g->shape();
        QPolygonF poly_shape=ptr_wiC_g->get_polygon();
        QPointF pp_1=rectf.topLeft();
        QPointF pp_2=rectf.bottomRight();
        rectf.translate(p_2.x()-p_3.x(),p_2.y()-p_3.y());
        QPainterPath path_shape_2=path_shape;
        QPolygonF poly_shape_2=poly_shape;
        path_shape_2.translate(p_2.x()-p_3.x(),p_2.y()-p_3.y());
        poly_shape_2.translate(p_2.x()-p_3.x(),p_2.y()-p_3.y());

        this->scene()->removeItem(ptr_wiC_g);//astuce a la noix
        list_widgCell.removeOne(ptr_wiC_g);

        QColor coul;
        coul.setRgb(255,255,255,0);

        ptr_wiC_g->set_couleur(coul);
        int index=ptr_wiC_g->get_index();
        double angle=ptr_wiC_g->get_angle();

        delete ptr_wiC_g;
        ptr_wiC_g=NULL;


        if(intersecte_cell(path_shape_2))
        {
            if(create_cell(pp_1,pp_2))//creation de la cell
            {
                list_widgCell[list_widgCell.size()-1]->set_shape(path_shape,poly_shape);//pas top
                list_widgCell[list_widgCell.size()-1]->set_index(index);
                list_widgCell[list_widgCell.size()-1]->set_angle(angle);
            }
        }
        else
        {
            if(create_cell(rectf.topLeft(),rectf.bottomRight()))
            {
                list_widgCell[list_widgCell.size()-1]->set_shape(path_shape_2,poly_shape_2);

                list_widgCell[list_widgCell.size()-1]->set_index(index);
                list_widgCell[list_widgCell.size()-1]->set_angle(angle);

                double x,y,w,h;
                x=list_widgCell[list_widgCell.size()-1]->get_rect_eff().topLeft().x();
                y=list_widgCell[list_widgCell.size()-1]->get_rect_eff().topLeft().y();
                w=list_widgCell[list_widgCell.size()-1]->get_rect_eff().width();
                h=list_widgCell[list_widgCell.size()-1]->get_rect_eff().height();

                Pos pos={x,y,w,h,angle};
                emit modif_cell(index,pos);
            }

        }

        //liaison===============

        if(move_liaison)
        {
            move_liaison=false;

            ptr_wiC_g=list_widgCell[list_widgCell.size()-1];
            ptr_wiC_g->setZValue(0);


            this->scene()->removeItem(wiL_temp);
            delete wiL_temp;
            wiL_temp=NULL;

            WidgLi *wiL;
            wiL =new WidgLi(ptr_wiC_g->boundingRect().center(),ctr_2);
            this->scene()->addItem(wiL);


            ptr_wiC_g->set_ptr_cell_li(ptr_wiC_e);
            ptr_wiC_e->set_ptr_cell_li(ptr_wiC_g);
            ptr_wiC_g->set_have_cpl(true);
            ptr_wiC_e->set_have_cpl(true);
            ptr_wiC_g->set_ptr_li(wiL);
            ptr_wiC_e->set_ptr_li(wiL);
            wiL->set_ptr_bout(ptr_wiC_g);
            list_widgLi << wiL;

            ptr_wiC_g->stackBefore(list_widgLi.at(0));//list_widgLi.at(0)) le premier stocké ?


        }

        update();


        deplacement=false;
        setCursor(Qt::OpenHandCursor);
    }
}


//============================================DES CELL==========================================
//PRESS....................................................................................... 
void MaGraphicsView::mousePressEvent_DES_CELL(QMouseEvent *event)
{
}

//MOVE.........................................................................................
void MaGraphicsView::mouseMoveEvent_DES_CELL(QMouseEvent *event)
{

    p_2=event->pos();

    if(wicell_temp!=NULL){this->scene()->removeItem(wicell_temp);}

    create_cell_temp(p_1,p_2);//fuite memoire?
    update();//utile?

}


//RELEASE...................................................................................
void MaGraphicsView::mouseReleaseEvent_DES_CELL(QMouseEvent *event)
{
    if(event->button()== Qt::LeftButton)
    {

        this->scene()->removeItem(wicell_temp);
        delete wicell_temp;
        wicell_temp=NULL;
        p_2=event->pos();

        QRectF r(p_2,p_1);
        QPainterPath path;
        path.addRect(r);

        if(!intersecte_cell(path))
        {
            if(create_cell(p_1,p_2))
            {
                int index=list_widgCell.size()-1;
                list_widgCell[list_widgCell.size()-1]->set_index(index);
                double x,y,w,h;
                x=list_widgCell[list_widgCell.size()-1]->get_rect_eff().topLeft().x();
                y=list_widgCell[list_widgCell.size()-1]->get_rect_eff().topLeft().y();
                w=list_widgCell[list_widgCell.size()-1]->get_rect_eff().width();
                h=list_widgCell[list_widgCell.size()-1]->get_rect_eff().height();

                Pos pos={x,y,w,h,0};//l'angle est nul lors de la creation...
                emit add_cell(pos);

            }

        }

        setMode(ViewMode::CELL);

        update();

    }
}



//===========================================CPL================================================

//PRESS........................................................................................

void MaGraphicsView::mousePressEvent_CPL(QMouseEvent *event)
{
    if(event->button()== Qt::LeftButton)
    {

        p_1=event->pos();

        ptr_wiC_a=find_cell(p_1);
        if(ptr_wiC_a!=NULL && (!ptr_wiC_a->have_cpl()))
        {
            setMode(ViewMode::BAR_CPL);
            QColor coul;
            coul.setRgb(10,250,250,100);
            ptr_wiC_a->set_couleur(coul);

        }

    }
}

//...............................................MOVE............................................

void MaGraphicsView::mouseMoveEvent_CPL(QMouseEvent *event)
{

    WidgCell *ptr_wiC_zou=NULL;
    ptr_wiC_zou=ptr_wiC_e;
    ptr_wiC_e=find_cell(event->pos());

    if(ptr_wiC_e!=NULL && !ptr_wiC_e->have_cpl())
    {
        QColor coul;
        coul.setRgb(10,250,250,100);
        ptr_wiC_e->set_couleur(coul);
    }
    if(ptr_wiC_e==NULL && ptr_wiC_zou != NULL )
    {
        QColor coul;
        coul.setRgb(255,255,255,0);
        ptr_wiC_zou->set_couleur(coul);//problème lorsque 2 fenêtres;
    }

}

//..............................................RELEASE.........................................

void MaGraphicsView::mouseReleaseEvent_CPL(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
}

//==========================================BAR CPL============================================

//.............................................PRESS............................................

void MaGraphicsView::mousePressEvent_BAR_CPL(QMouseEvent *event)
{
}

//..............................................MOUVE..........................................

void MaGraphicsView::mouseMoveEvent_BAR_CPL(QMouseEvent *event)
{

    p_2=event->pos();

    ptr_wiC_d=ptr_wiC_c;
    ptr_wiC_c=find_cell(p_2);
    if(ptr_wiC_c==NULL && ptr_wiC_d != NULL && ptr_wiC_d != ptr_wiC_a )
    {
        QColor coul;
        coul.setRgb(255,255,255,0);
        ptr_wiC_d->set_couleur(coul);
    }
    if(ptr_wiC_c!=NULL && ptr_wiC_a != ptr_wiC_c && (! ptr_wiC_c->have_cpl()))
    {
        QColor coul;
        coul.setRgb(10,250,250,100);
        ptr_wiC_c->set_couleur(coul);

    }

    if(wiL_temp!=NULL){this->scene()->removeItem(wiL_temp);}
    wiL_temp= new WidgLi(p_1,p_2);
    this->scene()->addItem(wiL_temp);

    //TODO faire des item plutot que obj pr gaspiller moins de memoire
    update();

}

//..........................................RELEASE.............................................

void MaGraphicsView::mouseReleaseEvent_BAR_CPL(QMouseEvent *event)
{
    if(event->button()== Qt::LeftButton)
    {

        this->scene()->removeItem(wiL_temp);
        delete wiL_temp;
        wiL_temp=NULL;
        p_2=event->pos();

        ptr_wiC_b=find_cell(p_2);
        if(ptr_wiC_b!=NULL && ptr_wiC_a != ptr_wiC_b &&(! ptr_wiC_b->have_cpl()))
        {
            QPointF p_a=ptr_wiC_a->get_centre();
            QPointF p_b=ptr_wiC_b->get_centre();

            WidgLi *wiL;
            wiL =new WidgLi(p_a,p_b);
            this->scene()->addItem(wiL);

            ptr_wiC_b->set_ptr_cell_li(ptr_wiC_a);
            ptr_wiC_a->set_ptr_cell_li(ptr_wiC_b);
            ptr_wiC_b->set_have_cpl(true);
            ptr_wiC_a->set_have_cpl(true);
            ptr_wiC_b->set_ptr_li(wiL);
            ptr_wiC_a->set_ptr_li(wiL);
            wiL->set_ptr_bout(ptr_wiC_a);
            list_widgLi << wiL;

            emit add_cpl(ptr_wiC_a->get_index(),ptr_wiC_b->get_index());

            QColor coul;
            coul.setRgb(255,255,255,0);

            ptr_wiC_b->set_couleur(coul);
            ptr_wiC_a->set_couleur(coul);

            update();

        }

        QColor coul;
        coul.setRgb(255,255,255,0);

        ptr_wiC_a->set_couleur(coul);

        setMode(ViewMode::CPL);


    }
}



//===============================================COPIE========================================

//.........................................PRESS............................................

void MaGraphicsView::mousePressEvent_COPIE(QMouseEvent *event)
{
    if(event->button()== Qt::LeftButton)
    {

        p_1=event->pos();
        p_3=p_1;//?
        ptr_wiC_d=find_cell(p_1);

        if(ptr_wiC_d!=NULL)
        {
            ptr_wiC_g=new WidgCell(ptr_wiC_d->get_rect_eff());
            ptr_wiC_g->set_shape(ptr_wiC_d->shape(),ptr_wiC_d->get_polygon());
            this->scene()->addItem(ptr_wiC_g);
            pos_1=ptr_wiC_g->pos();
            ptr_wiC_g->setZValue(1);
            QColor coul;
            coul.setRgb(100,255,100);
            ptr_wiC_g->set_couleur(coul);
            coul.setRgb(255,255,255,0);
            ptr_wiC_d->set_couleur(coul);

            setCursor(Qt::ClosedHandCursor);
            deplacement=true;
        }

    }
}

//...............................................MOVE..........................................

void MaGraphicsView::mouseMoveEvent_COPIE(QMouseEvent *event)
{

    p_2=event->pos();
    if(deplacement)
    {

        setCursor(Qt::ClosedHandCursor);
        pos_1.setX(pos_1.x()+(p_2.x()-p_1.x()));
        pos_1.setY(pos_1.y()+(p_2.y()-p_1.y()));

        ptr_wiC_g->setPos(pos_1);
        QColor coul;
        coul.setRgb(100,255,100);

        ptr_wiC_g->set_couleur(coul);

        p_1=p_2;
        update();

    }
    else
    {
        //si bouton pas presse et seulement entree et sortie pour ne pas gaspiller de la memoire TODO
        ptr_wiC_g=find_cell(p_2);

        if (ptr_wiC_g!=NULL)
        {
            setCursor(Qt::OpenHandCursor);
            QColor coul;
            coul.setRgb(100,255,100);

            ptr_wiC_g->set_couleur(coul);
            ptr_wiC_a=ptr_wiC_g;
        }
        else
        {
            setCursor(Qt::ArrowCursor);
            if(ptr_wiC_a!=0)
            {
                QColor coul;
                coul.setRgb(255,255,255,0);
                ptr_wiC_a->set_couleur(coul);
            }
        }
    }
}



//............................................RELEASE........................................

void MaGraphicsView::mouseReleaseEvent_COPIE(QMouseEvent *event)
{
    if(deplacement)
    {
        //mal codé...
        p_2=event->pos();
        pos_1.setX(pos_1.x()+(p_2.x()-p_1.x()));
        pos_1.setY(pos_1.y()+(p_2.y()-p_1.y()));

        ptr_wiC_g->setPos(pos_1);
        QRectF rectf=ptr_wiC_g->get_rect_eff();//de l'ancienne pos
        QPainterPath path_shape=ptr_wiC_g->shape();
        QPolygonF poly_shape=ptr_wiC_g->get_polygon();

        QPointF pp_1=rectf.topLeft();
        QPointF pp_2=rectf.bottomRight();
        QPainterPath path_shape_2=path_shape;
        QPolygonF poly_shape_2=poly_shape;

        path_shape_2.translate(p_2.x()-p_3.x(),p_2.y()-p_3.y());
        poly_shape_2.translate(p_2.x()-p_3.x(),p_2.y()-p_3.y());

        rectf.translate(p_2.x()-p_3.x(),p_2.y()-p_3.y());
        this->scene()->removeItem(ptr_wiC_g);//astuce a la noix
        list_widgCell.removeOne(ptr_wiC_g);


        QColor coul;
        coul.setRgb(255,255,255,0);

        ptr_wiC_g->set_couleur(coul);

        delete ptr_wiC_g;
        ptr_wiC_g=NULL;

        if(intersecte_cell(path_shape_2))
        {
            //rien ?...

        }
        else
        {
            if(create_cell(rectf.topLeft(),rectf.bottomRight()))
            {
                list_widgCell[list_widgCell.size()-1]->set_shape(path_shape_2,poly_shape_2);

                int index=list_widgCell.size()-1;
                double angle=ptr_wiC_d->get_angle();

                list_widgCell[list_widgCell.size()-1]->set_index(index);
                list_widgCell[list_widgCell.size()-1]->set_angle(angle);

                double x,y,w,h;
                x=list_widgCell[list_widgCell.size()-1]->get_rect_eff().topLeft().x();
                y=list_widgCell[list_widgCell.size()-1]->get_rect_eff().topLeft().y();
                w=list_widgCell[list_widgCell.size()-1]->get_rect_eff().width();
                h=list_widgCell[list_widgCell.size()-1]->get_rect_eff().height();

                Pos pos={x,y,w,h,angle};
                emit add_cell(pos);
            }
        }


        update();

        deplacement=false;
        setCursor(Qt::OpenHandCursor);
    }
}



//===============================================SUPR==========================================

//...............................................PRESS.........................................

void MaGraphicsView::mousePressEvent_SUPRR(QMouseEvent *event)
{
    p_1=event->pos();

    ptr_li_a=find_li(p_1);
    if(ptr_li_a!=NULL)
    {
        ptr_wiC_d=ptr_li_a->get_ptr_bout();
        ptr_wiC_e=ptr_wiC_d->get_ptr_cell_li();
        ptr_wiC_d->set_ptr_cell_li(NULL);
        ptr_wiC_e->set_ptr_cell_li(NULL);
        ptr_wiC_d->set_ptr_li(NULL);
        ptr_wiC_e->set_ptr_li(NULL);
        ptr_wiC_d->set_have_cpl(false);
        ptr_wiC_e->set_have_cpl(false);

        emit supr_cpl(ptr_wiC_d->get_index(),ptr_wiC_e->get_index());

        this->scene()->removeItem(ptr_li_a);
        list_widgLi.removeOne(ptr_li_a);//fuite memoire?


    }
    else
    {
        ptr_wiC_a=find_cell(p_1);
        if(ptr_wiC_a!=NULL)
        {
            int index=ptr_wiC_a->get_index();
            emit supr_cell(index);
            this->scene()->removeItem(ptr_wiC_a);
            list_widgCell.removeOne(ptr_wiC_a);//fuite memoire?

            //========aj post supr==================
            for(int i=0;i<list_widgCell.size();i++)
            {
                if((list_widgCell[i]->get_index())>index)
                {
                    list_widgCell[i]->set_index((list_widgCell[i]->get_index())-1);
                }
            }

            //======================================
            if((ptr_wiC_a->get_ptr_li())!=NULL)
            {
                ptr_li_b=ptr_wiC_a->get_ptr_li();//mal codé faire des maps...
                ptr_wiC_b=ptr_wiC_a->get_ptr_cell_li();
                ptr_wiC_a->set_ptr_cell_li(NULL);
                ptr_wiC_b->set_ptr_cell_li(NULL);
                ptr_wiC_b->set_ptr_li(NULL);
                ptr_wiC_b->set_have_cpl(false);


                this->scene()->removeItem(ptr_li_b);
                list_widgLi.removeOne(ptr_li_b);//fuite memoire?


            }

        }
    }
}

//..............................................MOVE.............................................

//TODO resoudre bug passage rapide 
void MaGraphicsView::mouseMoveEvent_SUPRR(QMouseEvent *event)
{
    ptr_li_b=ptr_li_a;
    ptr_li_a=find_li(event->pos());
    if(ptr_li_a!=NULL )
    {
        if(ptr_wiC_e!=NULL)
        {
            QColor coul;
            coul.setRgb(255,255,255,0);
            ptr_wiC_e->set_couleur(coul);
        }
        QColor coul;
        coul.setRgb(250,10,10,100);
        ptr_li_a->set_couleur(coul);

    }
    if(ptr_li_a==NULL && ptr_li_b != NULL )
    {
        QColor coul;
        coul.setRgb(90,5,200,130);
        ptr_li_b->set_couleur(coul);
    }

    if(ptr_li_a==NULL)
    {
        ptr_wiC_f=ptr_wiC_e;
        ptr_wiC_e=find_cell(event->pos());
        if(ptr_wiC_e!=NULL )
        {
            QColor coul;
            coul.setRgb(250,10,10,100);
            ptr_wiC_e->set_couleur(coul);
        }
        if(ptr_wiC_e==NULL && ptr_wiC_f != NULL )
        {
            QColor coul;
            coul.setRgb(255,255,255,0);
            ptr_wiC_f->set_couleur(coul);
        }
    }
}



//................................................RELEASE.......................................

void MaGraphicsView::mouseReleaseEvent_SUPRR(QMouseEvent *event)
{
}


//===============================================ROTATION=======================================

//PRESS.............................................................................
void MaGraphicsView::mousePressEvent_ROT(QMouseEvent *event)
{

    p_1=event->pos();
    ptr_wiC_g=find_cell(p_1);

    if(ptr_wiC_g!=NULL)
    {

        if(!intersecte_cell_lui_exclu(ptr_wiC_g->rotated_shape(),list_widgCell.indexOf(ptr_wiC_g)))
        {

            ptr_wiC_g->rotation();
            int index;
            index=ptr_wiC_g->get_index();
            double x,y,l,h,ang;
            QRectF rect=ptr_wiC_g->get_rect_eff();
            x=rect.topLeft().x();
            y=rect.topLeft().y();
            l=rect.width();
            h=rect.height();
            ang=ptr_wiC_g->get_angle();
            Pos pos{x,y,l,h,ang};
            emit modif_cell(index,pos);
        }

    }
    update();
}




//MOVE..................................................................................
void MaGraphicsView::mouseMoveEvent_ROT(QMouseEvent *event)
{
}
//RELEASE.........................................................................
void MaGraphicsView::mouseReleaseEvent_ROT(QMouseEvent *event)
{
}
void  MaGraphicsView::mouseDoubleClickEvent_ROT(QMouseEvent *event)
{
    //le test de la rotation est ici pr l'instant
    mousePressEvent_ROT(event);

}





//===============================================================================================
void MaGraphicsView::create_cell_temp(const QPointF & pt_1,const QPointF & pt_2)
{
    QRectF rect;
    if((pt_1.x()<pt_2.x())&&(pt_1.y()<pt_2.y()))
    {
        QRectF r(pt_1,pt_2);
        rect=r;

    }
    if((pt_1.x()<pt_2.x())&&(pt_1.y()>=pt_2.y()))
    {
        QPointF pt_1_bis;
        QPointF pt_2_bis;
        pt_1_bis.setX(pt_1.x());
        pt_1_bis.setY(pt_2.y());
        pt_2_bis.setX(pt_2.x());
        pt_2_bis.setY(pt_1.y());
        QRectF r(pt_1_bis,pt_2_bis);
        rect=r;


    }
    if((pt_1.x()>=pt_2.x())&&(pt_1.y()<pt_2.y()))
    {
        QPointF pt_1_bis;
        QPointF pt_2_bis;
        pt_1_bis.setX(pt_2.x());
        pt_1_bis.setY(pt_1.y());
        pt_2_bis.setX(pt_1.x());
        pt_2_bis.setY(pt_2.y());
        QRectF r(pt_1_bis,pt_2_bis);
        rect=r;

    }

    if((pt_1.x()>=pt_2.x())&&(pt_1.y()>=pt_2.y()))
    {
        QRectF r(pt_2,pt_1);
        rect=r;

    }

    QRectF rect_f(rect);

    wicell_temp =new WidgCell(rect_f);

    this->scene()->addItem(wicell_temp);
    if(list_widgLi.size()>0)
    {wicell_temp->stackBefore(list_widgLi.at(0));}

}


bool MaGraphicsView::create_cell(const QPointF & pt_1,const QPointF & pt_2)
{
    QRectF rect;
    if((pt_1.x()<pt_2.x())&&(pt_1.y()<pt_2.y()))
    {
        QRectF r(pt_1,pt_2);
        rect=r;
    }
    if((pt_1.x()<pt_2.x())&&(pt_1.y()>=pt_2.y()))
    {
        QPointF pt_1_bis;
        QPointF pt_2_bis;
        pt_1_bis.setX(pt_1.x());
        pt_1_bis.setY(pt_2.y());
        pt_2_bis.setX(pt_2.x());
        pt_2_bis.setY(pt_1.y());
        QRectF r(pt_1_bis,pt_2_bis);
        rect=r;

    }
    if((pt_1.x()>=pt_2.x())&&(pt_1.y()<pt_2.y()))
    {
        QPointF pt_1_bis;
        QPointF pt_2_bis;
        pt_1_bis.setX(pt_2.x());
        pt_1_bis.setY(pt_1.y());
        pt_2_bis.setX(pt_1.x());
        pt_2_bis.setY(pt_2.y());
        QRectF r(pt_1_bis,pt_2_bis);
        rect=r;

    }

    if((pt_1.x()>=pt_2.x())&&(pt_1.y()>=pt_2.y()))
    {
        QRectF r(pt_2,pt_1);
        rect=r;
    }

    QRectF rect_f(rect);
    if(cell_size_acceptable(rect))//sinon on ne crée rien (bof)
    {
        WidgCell *wiB;
        wiB =new WidgCell(rect_f);

        this->scene()->addItem(wiB);
        if(list_widgLi.size()>0)
        {wiB->stackBefore(list_widgLi.at(0));}


        list_widgCell << wiB;
        return true;
    }
    else
    {
        return false;
    }
}


//??
void MaGraphicsView::creer_wil_temp(const QPointF & pt_1,const QPointF & pt_2)
{

}

//??
void MaGraphicsView::creer_wil(const QPointF & pt_1,const QPointF & pt_2)
{

}




void MaGraphicsView::dragEnterEvent(QDragEnterEvent * event)
{
    event->accept();
}



void MaGraphicsView::dragMoveEvent(QDragMoveEvent * event)
{
    event->accept();
}



void MaGraphicsView::dropEvent(QDropEvent * event)
{
    event->accept();
}


WidgCell*  MaGraphicsView::find_cell(const QPointF & point)
{
    for(int i=0;i<list_widgCell.size();i++)
    {
        if(list_widgCell.at(i)->shape().contains(point))return(list_widgCell.at(i));
    }
    return(NULL);
}

WidgLi*  MaGraphicsView::find_li(const QPointF & point)
{
    for(int i=0;i<list_widgLi.size();i++)
    {
        if(list_widgLi.at(i)->shape().contains(point))return(list_widgLi.at(i));
    }
    return(NULL);
}


bool  MaGraphicsView::intersecte_cell(const QRectF & rect)
{

    for(int i=0;i<list_widgCell.size();i++)
    {
        if(rect.intersects(list_widgCell.at(i)->boundingRect()))return true;
    }
    return false;
}


bool  MaGraphicsView::intersecte_cell(const QPainterPath & shape_path)
{

    for(int i=0;i<list_widgCell.size();i++)
    {
        if(shape_path.intersects(list_widgCell.at(i)->shape()))return true;
    }
    return false;
}


bool  MaGraphicsView::intersecte_cell_lui_exclu(const QPainterPath & shape_path,int ind)
{

    for(int i=0;i<list_widgCell.size();i++)
    {

        if((i!=ind)&&shape_path.intersects(list_widgCell.at(i)->shape()))return true;
    }
    return false;
}


void MaGraphicsView::setMode( ViewMode vM)
{
    mode=vM;
}



bool MaGraphicsView::cell_size_acceptable(const QRectF &rect)
{
    if((rect.width()<MINIMAL_WIDTH)||(rect.height()<MINIMAL_HEIGTH)||(rect.width()>MAXIMAL_WIDTH)||(rect.height()>MAXIMAL_HEIGTH))
    {
        return false;
    }
    else
    {
        return true;
    }
}



void MaGraphicsView::wheelEvent(QWheelEvent *event)
{
    event->accept();

    if(mode==ViewMode::NOMODE)
    {
        scaleView(pow((double)2,-event->angleDelta().y()/ 500.0));

    }
    else
    {
        QGraphicsView::wheelEvent(event);
    }
}



void MaGraphicsView::scaleView(qreal scaleFactor)
{

    qreal factor = transform().scale(scaleFactor,scaleFactor).mapRect(QRectF(0,0,1,1)).width();
    if(factor <0.07 || factor > 100)
        return;
    emit resize(scaleFactor);
}



void FenRoDes::resize(qreal sf_r)
{
}

void MaGraphicsView::effectuer_rot(int ind)
{
    list_widgCell[ind]->rotation();
}


void  MaGraphicsView::mouseDoubleClickEvent_CELL(QMouseEvent *event)
{

}
void  MaGraphicsView::mouseDoubleClickEvent_DES_CELL(QMouseEvent *event)
{

}
void  MaGraphicsView::mouseDoubleClickEvent_CPL(QMouseEvent *event)
{

}
void  MaGraphicsView::mouseDoubleClickEvent_BAR_CPL(QMouseEvent *event)
{

}
void  MaGraphicsView::mouseDoubleClickEvent_COPIE(QMouseEvent *event)
{

}
void  MaGraphicsView::mouseDoubleClickEvent_SUPRR(QMouseEvent *event)
{

}



