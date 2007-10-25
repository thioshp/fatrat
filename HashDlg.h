#ifndef HASHDLG_H
#define HASHDLG_H
#include <QCryptographicHash>
#include <QDialog>
#include <QThread>
#include <QFile>
#include "ui_HashDlg.h"

class HashThread : public QThread
{
Q_OBJECT
public:
	HashThread(QFile* file);
	void setAlgorithm(QCryptographicHash::Algorithm alg) { m_alg = alg; }
	void run();
signals:
	void progress(int pcts);
	void finished(QByteArray result);
private:
	QCryptographicHash::Algorithm m_alg;
	QFile* m_file;
};

class HashDlg : public QDialog, Ui_HashDlg
{
Q_OBJECT
public:
	HashDlg(QWidget* parent = 0, QString file = QString());
	~HashDlg();
	
private slots:
	void browse();
	void compute();
	void finished(QByteArray result);
private:
	QFile m_file;
	HashThread m_thread;
};

#endif
