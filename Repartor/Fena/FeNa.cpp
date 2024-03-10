#include "FeNa.h"



using namespace std; 

FeNa::FeNa() :QWidget()
{
setMinimumSize(700,300);
//=========ajout N===============================
bouton=new QPushButton("+",this);
bouton->setFixedSize(30,30);
//bouton->setFocus();
//bouton->setDefault(true);//repond tjrs au bouton  entrée
line=new MaLineEdit();
line->setText("");
line->setParent(this);
line->setFixedSize(200,30);
//line->setFocus();//focus clavier
lay=new QHBoxLayout();
lay->addWidget(line);
lay->addWidget(bouton);
//=========container N==========================
m_w_multi_aff=new QWidget(this);
//m_w_multi_aff->setMinimumSize(200,250);
 m_scroll_multi_aff=new  QScrollArea();
 m_scroll_multi_aff->setWidget(m_w_multi_aff);
m_vboxlayout_pr_aff=new QVBoxLayout();
 m_vboxlayout_pr_aff->setAlignment(Qt::AlignCenter);
 m_vboxlayout_pr_aff->setSizeConstraint(QLayout::SetNoConstraint);//utile?
 m_w_multi_aff->setLayout(m_vboxlayout_pr_aff);
//=================================================
l=new QHBoxLayout();
l->addWidget(m_scroll_multi_aff);
l->addLayout(lay);
l->setStretchFactor(m_scroll_multi_aff,1);//marche pas car scroll?
l->setStretchFactor(lay,80);

this->setLayout(l);
connect(bouton,SIGNAL(clicked()),this,SLOT(addN()));
connect(this,SIGNAL(addNS(QString)),this,SLOT(nouvelle_fen_N(QString)));
connect(line,SIGNAL(enter()),this,SLOT(addN()));

bouton->setDefault(true);//repond tjrs au bouton  entrée
line->setFocus();//focus clavier

}


MaLineEdit::MaLineEdit() :QLineEdit()
{
}


void MaLineEdit::keyPressEvent(QKeyEvent * event)
{
//cout<<event->key()<<endl;
if((event->key())!=16777220)//16777220 ->entrée platform dependant??!!!
{QLineEdit::keyPressEvent(event);
}
else
{
emit enter();
}
}

/*
void FeNa::showEvent()
{
bouton->setDefault(true);//repond tjrs au bouton  entrée
line->setFocus();//focus clavier

}*/

void FeNa::addN()
{
if((line->text()!="")&&(N_libre()))
{
emit addNS(line->text());
line->setText("");
line->setFocus();
}
}

bool FeNa::N_libre()
{
if(N_str_list.contains(line->text())){return false;}
else{return true;}
}

void FeNa::nouvelle_fen_N(QString string_N)
{
//TODO verifier que le nom est libre...
N_str_list << string_N;
emit aj_list(N_str_list);
  widgN *nouv_fen;
       nouv_fen = new widgN();
       nouv_fen->setN(string_N);
            N_list << nouv_fen;


    m_vboxlayout_pr_aff->addWidget(nouv_fen);
       
   
   m_w_multi_aff->resize(nouv_fen->width()+10,m_w_multi_aff->height()+nouv_fen->height()+10);
//cout<<N_list.size()<<endl;;
connect(nouv_fen,SIGNAL(detruit_moi(widgN*)),this,SLOT(detruire_N(widgN*)));
}
void FeNa::detruire_N(widgN* wN)
{
N_str_list.removeAt(N_str_list.indexOf(wN->getN()));
emit aj_list(N_str_list);

int hdel=wN->height();
N_list.removeAt(N_list.indexOf(wN));
delete wN;
wN=NULL;
 m_w_multi_aff->resize( m_w_multi_aff->width(),m_w_multi_aff->height()-hdel-10);

}


widgN::widgN() :QWidget()
{
    setFixedSize(260,35);

    m_label_N = new QLabel("",this);
    m_label_N -> setFixedSize(240,20);
    //m_label_N -> move(10,10);

     QFont font=m_label_N->font();
    font.setPointSize(10);
    
  
    m_label_N->setFont(font);
  
QHBoxLayout *lay=new QHBoxLayout();
QPushButton *but=new QPushButton("x");
but->setFixedSize(15,15);
lay->addWidget(m_label_N);
lay->addWidget(but);
this->setLayout(lay);
connect(but,SIGNAL(clicked()),this,SLOT(destruction()));



  QPaintEvent paintevent();//???


}

widgN::~widgN() 
{
}
  void widgN::destruction()
{
//QWidget::~QWidget();
//~widgN();
//delete this;
emit detruit_moi(this);
}

  void widgN::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    painter.setPen(pen);
    QRect rect_ajuste(this->rect());
    rect_ajuste.setWidth(rect_ajuste.width()-1);
    rect_ajuste.setHeight(rect_ajuste.height()-1);

  
     QColor couleur;
    
     couleur.setCmyk(40,40,40,30);

     QPainterPath path_rect;
     path_rect.addRect(rect_ajuste);
     QBrush brosse(Qt::SolidPattern);
     brosse.setColor(couleur);
     painter.fillPath(path_rect,brosse);
    // painter.drawRect(rect_ajuste);


        
}
 void widgN::setN(QString string_N)
{
      m_label_N->setText(string_N);
}
 
QString widgN::getN()
{
return m_label_N->text();
}
