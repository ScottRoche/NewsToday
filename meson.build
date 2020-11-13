project('newstoday', 'c')

nt_src = ['src/main.c', 
          'src/nt-application.c', 
          'src/nt-window.c', 
          'src/nt-rss-parser.c'
         ]

gtkdep = dependency('gtk+-3.0')
grssdep = dependency('libgrss')

gnome = import('gnome')
nt_src += gnome.compile_resources('nt-resources',
     'src/nt.gresource.xml',
     c_name: 'nt'
)

executable('newstoday', nt_src, dependencies : [gtkdep, grssdep])