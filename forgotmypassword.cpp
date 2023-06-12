#include "forgotmypassword.h"
#include "ui_forgotmypassword.h"

ForgotMyPassword::ForgotMyPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ForgotMyPassword)
{
    ui->setupUi(this);
    ui->pass->hide();

    ui->passL->hide();
    ui->confirm->hide();
    ui->confirm_pass->hide();
    ui->confirm_passL->hide();
}

ForgotMyPassword::~ForgotMyPassword()
{
    delete ui;
}

void ForgotMyPassword::on_check_clicked()
{

    ui->check->setEnabled(false);

    QPropertyAnimation* fade_out =new QPropertyAnimation(ui->check,"geometry");
    fade_out->setDuration(500);

    fade_out->setStartValue(QRect(ui->check->x(),ui->check->y(),ui->check->width(),ui->check->height()) );
    fade_out->setEndValue(QRect(ui->check->x()+ui->check->width()/2,ui->check->y()+ui->check->height()/2,0,0) );
    fade_out->start();
    connect(fade_out,&QPropertyAnimation::finished,this,&ForgotMyPassword::EndOfFadingOut);



}


void ForgotMyPassword::EndOfFadingOut(){
    ui->user->hide();
    ui->userL->hide();
    ui->email->hide();
    ui->emailL->hide();
    ui->pass->show();
    ui->passL->show();
    ui->confirm->show();
    ui->confirm_pass->show();
    ui->confirm_passL->show();
    int height=ui->confirm->height();
    int width=ui->confirm->width();
    QPropertyAnimation *fade_in = new QPropertyAnimation(ui->confirm,"geometry");
    fade_in->setDuration( 500 );
    fade_in->setStartValue( QRect(ui->confirm->x()+width/2,ui->confirm->y()+height/2,0,0) );
    fade_in->setEndValue(QRect(ui->confirm->x(),ui->confirm->y(),width,height) );
    fade_in->start();
}
