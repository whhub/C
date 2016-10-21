//
// Created by hui.wang on 2016-10-21.
//

#ifndef SNIPPET_GLOBALDEFINITION_H
#define SNIPPET_GLOBALDEFINITION_H

#define DISABLE_ASSIGN_AND_COPY(ClassName) \
    ClassName& operator=(const ClassName&); \
    ClassName(const ClassName&);

#endif //SNIPPET_GLOBALDEFINITION_H
