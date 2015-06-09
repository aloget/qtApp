#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QObject>

class Configuration : public QObject
{
    Q_OBJECT
private:

public:
    explicit Configuration(QObject *parent = 0);//parse .ini file and init sources array

    static Configuration& getInstance();//singleton
    /*static S  instance; // Guaranteed to be destroyed.
                            // Instantiated on first use.
      return instance;*/

    Configuration(Configuration const&);
    void operator=(Configuration const&);

    enum SourceType {
        BOOK, MULTIPART_BOOK, ARTICLE, WEB
    };

signals:

public slots:
};

#endif // CONFIGURATION_H
