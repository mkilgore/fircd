/*
 * Copyright (C) 2013 Matt Kilgore
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License v2 as published by the
 * Free Software Foundation.
 */
#ifndef INCLUDE_CHANNEL_H
#define INCLUDE_CHANNEL_H

#include "global.h"

#include <sys/types.h>
#include <sys/select.h>

#include "buf.h"
#include "array.h"

/* 'channel' represents a node on a linked-list of channels */
struct channel {
    struct network *net;
    struct channel *next;

    char *name;

    ARRAY(char*, nicks);
    struct buf_fd infd;
    int outfd, onlinefd, topicfd, rawfd, msgsfd;
};

extern void channel_init (struct channel *);
extern void channel_init_select_desc (struct channel *);

extern void channel_setup (struct channel *);
extern void channel_setup_files (struct channel *);

extern void channel_handle_input (struct channel *);
extern void channel_handle_serv_line (struct channel *, const char *line);

extern void channel_write_raw (struct channel *, const char *msg);
extern void channel_write_out (struct channel *, const char *msg);
extern void channel_write_msg (struct channel *, const char *user, const char *line);
extern void channel_write_topic (struct channel *, const char *topic, const char *user);

extern void channel_clear (struct channel *);
extern void channel_clear_all (struct channel *);

extern void channel_add_nick (struct channel *, const char *nick);

#endif