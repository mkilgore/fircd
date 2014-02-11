/*
 * Copyright (C) 2013 Matt Kilgore
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License v2 as published by the
 * Free Software Foundation.
 */
#ifndef INCLUDE_FIRC_H
#define INCLUDE_FIRC_H

extern void init_directory(void);
extern void init_networks(void);
extern void set_select_desc(void);
extern void handle_file_check(void);
extern void setup_auto_load(void);

#endif